#include "stdafx.h"
#include "Player.h"
#include "Game1.h"
#include "Game2.h"
#include "Bullet.h"
#include "Bubble.h"

Player* Player::m_instance = nullptr;

Player::Player()
{

	//インスタンスの制限
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

	

	if (Pad(0).IsPress(enButtonLB2)&& m_timer >= 20) {
	

		Bullet* bullet = NewGO<Bullet>(0,"tama" );
		//弾丸の座標にプレイヤーの座標を代入する。
		bullet->SetPosition(m_position);
		//弾の方向と速度を設定する。
		bullet->SetMoveSpeed(Bullet_Direction());

		amo--;
		m_timer = 0;

	}

	if (Pad(0).IsPress(enButtonY) && amo <= 5) {
		//リロードのアニメーションをながして
		//アニメーションの再生中は弾を打てないようにする
		//弾薬の補充
		amo++;
	}

}

void Player::Player_Move()
{
	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//左スティックの入力量を受け取る。
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	//カメラの前方方向と右方向を取得。
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();

	//m_moveSpeed.y -= 980.0f * GameTime().GetFrameDeltaTime();
	//m_moveSpeed += cameraForward * lStick_y * 1.0f;	//奥方向への移動速度を加算。
	m_moveSpeed += cameraRight * lStick_x * 5.0f;		//右方向への移動速度を加算。
	m_moveSpeed.z = -0.5f;
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

//Bulletの打つ方向を取得
CVector3 Player::Bullet_Direction()
{
	//XZ成分の移動速度をクリア。
	d_moveSpeed.x = 0.0f;
	d_moveSpeed.z = 0.0f;

	//左スティックの入力量を受け取る。
	float RStick_x = Pad(0).GetRStickXF();
	float RStick_y = Pad(0).GetRStickYF();
	//カメラの前方方向と右方向を取得。
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	//XZ平面での前方方向、右方向に変換する。
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	cameraRight.y = 0.0f;
	cameraRight.Normalize();

	
	d_moveSpeed += cameraForward * RStick_y;	//奥方向への移動速度を加算。
	d_moveSpeed += cameraRight * RStick_x;		//右方向への移動速度を加算。

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