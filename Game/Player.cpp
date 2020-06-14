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

	m_animClips[enAnimationClip_walk].Load(L"animData/Player/Player.tka");
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	m_skinModelRender->Init(L"modelData/KPlayer.cmo"/*, m_animClips, 1*/);
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->FindMaterial([&](CModelEffect* mat) {
		mat->SetMaterialID(enMaterialID_Default);
	});
	//m_skinModelRender->PlayAnimation(enAnimationClip_walk);

	return true;
}

void Player::Update()
{
	Player_Move();

	//AnimationControl();

	m_timer++;


	if (tamakazu <= 0)
	{
		State = 1;
	}
	if (tamakazu > 0)
	{
		State = 0;
	}

	if (State == 0)
	{
		
		if (Pad(0).IsPress(enButtonLB2) && m_timer >= 10) {

			Bullet* bullet = NewGO<Bullet>(0, "tama");
			//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
			bullet->SetPosition(m_position);
			//�e�̕����Ƒ��x��ݒ肷��B
			bullet->SetMoveSpeed(Bullet_Direction());

			s_effect = NewGO<prefab::CSoundSource>(0);
			s_effect->Init(L"sound/pati.wav");
			s_effect->Play(false);

			tamakazu--;
			m_timer = 0;
		}
			if (tama_State == 0)
			{

				//�e���E��
				if (Pad(0).IsPress(enButtonRB2) && tamakazu <= TamaCapa) {
					//�����[�h�̃A�j���[�V�������Ȃ�����
					//�A�j���[�V�����̍Đ����͒e��łĂȂ��悤�ɂ���
					//�e��̕�[
					tamakazu++;
					tama_State = 1;
				}

			}
			if (tama_State == 1)
			{
				t++;
				if (t > 10)
				{
					tama_State = 0;
					t = 0;
				}

			}
	}
	if (State == 1)
	{
		if (tama_State == 0)
		{

			//�e���E��
			if (Pad(0).IsPress(enButtonRB2) && tamakazu <= TamaCapa) {
				//�����[�h�̃A�j���[�V�������Ȃ�����
				//�A�j���[�V�����̍Đ����͒e��łĂȂ��悤�ɂ���
				//�e��̕�[
				tamakazu++;
				tama_State = 1;
			}

		}
		if (tama_State == 1)
		{
			t++;
			if (t > 20)
			{
				tama_State = 0;
			}

		}
	}

	

}

void Player::Player_Move()
{
	//XZ�����̈ړ����x���N���A�B
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

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
	//m_moveSpeed += cameraForward * lStick_y * 1.0f;	//�������ւ̈ړ����x�����Z�B
	m_moveSpeed += cameraRight * lStick_x * 3.0f;		//�E�����ւ̈ړ����x�����Z�B
	m_moveSpeed.z = -0.3f;
	m_position += m_moveSpeed;

	if (m_position.x > 95.0f)
	{
		m_position.x = 95.0f;
	}
	if (m_position.x < -95.0f)
	{
		m_position.x = -95.0f;
	}

	m_skinModelRender->SetPosition(m_position);

}

//Bullet�̑ł������擾
CVector3 Player::Bullet_Direction()
{
	//XZ�����̈ړ����x���N���A�B
	d_moveSpeed.x = 0.0f;
	d_moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��󂯎��B
	float RStick_x = Pad(0).GetRStickXF();
	float RStick_y = Pad(0).GetRStickYF();
	//�J�����̑O�������ƉE�������擾�B
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ���ʂł̑O�������A�E�����ɕϊ�����B
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();

	
	d_moveSpeed += cameraForward * RStick_y;	//�������ւ̈ړ����x�����Z�B
	d_moveSpeed += cameraRight * RStick_x;		//�E�����ւ̈ړ����x�����Z�B

	d_moveSpeed.Normalize();
	d_moveSpeed = d_moveSpeed * 3.0f;

	return d_moveSpeed;
}

/*
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
*/

