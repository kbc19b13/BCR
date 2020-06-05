#include "stdafx.h"
#include "Game1.h"
#include "Bullet.h"
#include "Bubble.h"
#include "BubbleChange.h"
#include "BubbleCluster.h"

Bullet::Bullet()
{
}
Bullet::~Bullet()
{
	DeleteGO(m_skinModelRender);
}

bool Bullet::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bullet.cmo");
	
	scale * 5.0f;
	m_skinModelRender->SetScale(scale);

	
	
	return true;
}

void Bullet::Update()
{
	m_moveSpeed -= m_moveSpeed * 0.02f;

	//�e�ۂ��ړ�������B
	m_position += m_moveSpeed;
	
	//�^�C�}�[�����Z����B
	m_timer++;
	if (m_timer >= 50 || 
		m_moveSpeed.x < 0.0f && m_moveSpeed.y < 0.0f && m_moveSpeed.z < 0.0f ||
		m_position.x > 95.0f ||
		m_position.x < -95.0f) {
		//�^�C�}�[��50�ɂȂ�����C���X�^���X���폜����B
		DeleteGO(this);
	}

	//�e��
	if (amo >= 0) {
		//�e��0�ɂȂ�����A
		//�����[�h�̃A�j���[�V�������Ȃ�����
		//�A�j���[�V�����̍Đ����͒e��łĂȂ��悤�ɂ���
		//�e���5�ǉ�����B

		amo += 5;

	}

	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
}
