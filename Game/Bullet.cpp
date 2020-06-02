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
	//�e�ۂ��ړ�������B
	m_position += m_moveSpeed;
	
	//�^�C�}�[�����Z����B
	//m_timer++;
	if (m_timer >= 50) {
		//�^�C�}�[��50�ɂȂ�����C���X�^���X���폜����B
		DeleteGO(this);
	}

	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
}
