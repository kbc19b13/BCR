#include "stdafx.h"
#include "Player.h"
#include "Game1.h"
#include "Game2.h"
#include "Bullet.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	//�C���X�^���X�̐���
	if (m_instance != nullptr)
	{
		std::abort();
	}

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	m_skinModelRender->Init(L"modelData/doll.cmo");

	m_charaCon.Init(10,50, m_position);

	m_instance = this;
}

Player::~Player()
{
	DeleteGO(m_skinModelRender);
	m_instance = nullptr;
}

void Player::Update()
{
	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//m_moveSpeed.x = Pad(0).GetLStickXF() * 250.0f;
	//m_moveSpeed.z = Pad(0).GetLStickYF() * 250.0f;

	//m_moveSpeed.y -= 20.0f;

	//���X�e�B�b�N�̓��͗ʂ��󂯎��B
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	//�J�����̑O�������ƉE�������擾�B
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();

	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	m_moveSpeed += cameraForward * lStick_y * 200.0f;	//�������ւ̈ړ����x�����Z�B
	m_moveSpeed += cameraRight * lStick_x * 200.0f;		//�E�����ւ̈ړ����x�����Z�B

	//AnimationControl();

	m_position = m_charaCon.Execute(m_moveSpeed);

	m_skinModelRender->SetPosition(m_position);

	if (Pad(0).IsPress(enButtonA)) {
		Bullet* bullet = NewGO<Bullet>(0);
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//Z��������400�̑��x��ݒ肷��B
		bullet->m_moveSpeed.z = 400.0f;

	}
	


}//}Player�̃��f���̈ʒu�����_�ɂ���ƃ��O�����邩���H