#include "stdafx.h"
#include "Player.h"
#include "Game1.h"
#include "Game2.h"
#include "Bullet.h"
#include "Bubble.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	//�C���X�^���X�̐���
	if (m_instance != nullptr)
	{
		std::abort();
	}

	

	m_instance = this;
}

Player::~Player()
{
	DeleteGO(m_skinModelRender);
	m_instance = nullptr;
}

bool Player::Start() 
{
	//awa = FindGO<Bubble>("awa");
	//game1 = FindGO<Game1>("game1");

	m_animClips[enAnimationClip_walk].Load(L"animData/Player/Player.tka");
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	m_skinModelRender->Init(L"modelData/doll.cmo"/*, m_animClips, 1*/);
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->FindMaterial([&](CModelEffect* mat) {
		mat->SetMaterialID(enMaterialID_Default);
	});
	//m_skinModelRender->PlayAnimation(enAnimationClip_walk);

	m_charaCon.Init(10, 50, m_position);
	return true;
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

	m_timer++;

	if (Pad(0).IsPress(enButtonA)&& m_timer >= 2) {
		Bullet* bullet = NewGO<Bullet>(0);
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//Z��������400�̑��x��ݒ肷��B
		bullet->m_moveSpeed.z = 400.0f;

		m_timer = 0;

	}
	
	/*
	QueryGOs<Bubble>("awa", [&](Bubble* awa)->bool {
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = awa->GetPosition() - m_position;
		if (diff.Length() < 50.0f) {	//������500�ȉ��ɂȂ�����B

			//GameOver2D���쐬����B
			//NewGO<GameOver2D>(0);

			CVector3 a = game1->GetScale();
			a.x -= 2.0f;
			game1->SetScale(a);

			//game1->s -= 2.0f;

			//�N�G���I���B
			return false;
		}
		return true;
		});
		*/

	m_position = m_charaCon.Execute(m_moveSpeed);
	m_skinModelRender->SetPosition(m_position);
}
void Player::AnimationControl()
{
	
	if (Pad(0).GetLStickXF()) {
		m_skinModelRender->PlayAnimation(enAnimationClip_walk);
	}
	else if (Pad(0).GetLStickXF()) {
		m_skinModelRender->PlayAnimation(enAnimationClip_walk);
	}
	else if (Pad(0).GetLStickYF()) {
		m_skinModelRender->PlayAnimation(enAnimationClip_walk);
	}
	else if (Pad(0).GetLStickYF()) {
		m_skinModelRender->PlayAnimation(enAnimationClip_walk);
	}
	
}
