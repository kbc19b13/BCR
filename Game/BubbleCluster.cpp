#include "stdafx.h"
#include "BubbleCluster.h"

void BubbleCluster::OnDestroy()
{
	for (auto bubble : m_bubblse) {
		DeleteGO(bubble);
	}
}
void BubbleCluster::AddBubble(Bubble* bubble)
{
	m_bubblse.push_back(bubble);
	if (m_bubblse.size() == 1) {
		//�o�u����Ȃ̂ŁA���x�����͂��Ȃ��B
		bcluster_moveSpeed = bubble->GetMoveSpeed();
	}else{
		//�o�u������������̂ŁA�d�ݕt���ő��x����������B
		//���x�𕽋ω��B
		float originalRate = 1.0f / m_bubblse.size();
		float rate = originalRate;
		bcluster_moveSpeed.Lerp( rate, bubble->GetMoveSpeed(), bcluster_moveSpeed ) ;
		//���x��A�̑傫���ɉ����Ēx������B
		bcluster_moveSpeed *= std::powf(originalRate, 0.01f);
		bcluster_moveSpeed.z = max(0.3f, bcluster_moveSpeed.z);	//��ʊO�ɗ����Ă���Ȃ��Ȃ�ƍ���̂ŁAz�̍ŏ��l��0.1�ɂ���B
	}
	bubble->BindBubbleCluster(this);
	
	
}
void BubbleCluster::UpdatePosition()
{
	//�N���X�^�[�̕��ύ��W���v�Z�B
	bcluster_position = CVector3::Zero;
	for (auto bubble : m_bubblse) {
		bcluster_position += bubble->GetPosition();
	}
	bcluster_position /= m_bubblse.size();
}
void BubbleCluster::UpdateRadius()
{
	//�N���X�^�[�̔��a���v�Z����B
	m_radius = 0.0f;
	for (auto bubble : m_bubblse) {
		auto pos = bubble->GetPosition();
		//�N���X�^�[�̒��S���W����A�o�u���܂ł̋������v�Z�B
		auto dist = pos - bcluster_position;
		float length = dist.Length();
		//���a���X�V�B
		if (m_radius < length) {
			//�������̂ق����傫���̂ŁA�X�V����B
			m_radius = length;
		}
	}
}
void BubbleCluster::Update()
{
	//�N���X�^�[�̍��W���X�V�B
	UpdatePosition();
	//�N���X�^�[�̔��a���X�V����B
	UpdateRadius();
	//���˂�����
	if (bcluster_position.x + m_radius > 75.0f			
		|| bcluster_position.x - m_radius < -75.0f
		) {
		//���ˁB
		bcluster_moveSpeed.x *= -1.0f;
	}
	//��ʊO�ɍs���Ǝ���
	if (bcluster_position.z - m_radius > 0.0f) {
		DeleteGO(this);
	}

}
void BubbleCluster::DeleteCluster() 
{
	/*
	�N���X�^�[�̗�����[�߂�
	Delete�����̎���
	�o
	�i���a���g�p����if�����쐬�j
	�N���X�^�[�S�̏�������̏����ɕϊ�
	�q���̃��X�g�����������Ă���
	�Ō�ɐe������
	�N���X�^�[�ƈꏏ�ɖA��������
	�p
	���ŘA��������H

	*/



}