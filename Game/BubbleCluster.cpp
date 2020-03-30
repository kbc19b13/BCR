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
		m_moveSpeed = bubble->GetMoveSpeed();
	}else{
		//�o�u������������̂ŁA�d�ݕt���ő��x����������B
		//���x�𕽋ω��B
		float originalRate = 1.0f / m_bubblse.size();
		float rate = originalRate;
		m_moveSpeed.Lerp( rate, bubble->GetMoveSpeed(), m_moveSpeed ) ;
		//���x��A�̑傫���ɉ����Ēx������B
		m_moveSpeed *= std::powf(originalRate, 0.01f);
		m_moveSpeed.z = max(0.3f, m_moveSpeed.z);	//��ʊO�ɗ����Ă���Ȃ��Ȃ�ƍ���̂ŁAz�̍ŏ��l��0.1�ɂ���B
	}
	bubble->BindBubbleCluster(this);
	//�N���X�^�[�̔��a���v�Z����B
	
}
void BubbleCluster::UpdatePosition()
{
	//�N���X�^�[�̕��ύ��W���v�Z�B
	m_position = CVector3::Zero;
	for (auto bubble : m_bubblse) {
		m_position += bubble->GetPosition();
	}
	m_position /= m_bubblse.size();
}
void BubbleCluster::UpdateRadius()
{
	m_radius = 0.0f;
	for (auto bubble : m_bubblse) {
		auto pos = bubble->GetPosition();
		//�N���X�^�[�̒��S���W����A�o�u���܂ł̋������v�Z�B
		auto dist = pos - m_position;
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
	//���a���X�V����B
	UpdateRadius();
	if (m_position.x + m_radius > 75.0f
		|| m_position.x - m_radius < -75.0f
		) {
		//���ˁB
		m_moveSpeed.x *= -1.0f;
	}

	if (m_position.z - m_radius > 0.0f) {
		DeleteGO(this);
	}

}