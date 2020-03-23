#include "stdafx.h"
#include "Bullet.h"

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
	return true;
}

void Bullet::Update()
{
	//�e�ۂ��ړ�������B
	m_position += m_moveSpeed;
	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
	//�^�C�}�[�����Z����B
	m_timer++;
	if (m_timer == 50) {
		//�^�C�}�[��50�ɂȂ�����C���X�^���X���폜����B
		DeleteGO(this);
	}

}
