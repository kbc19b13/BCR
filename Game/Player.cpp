#include "stdafx.h"
#include "Player.h"
#include "Game1.h"
#include "Game2.h"
#include "Bullet.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
	//インスタンスの制限
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
	//XZ成分の移動速度をクリア。
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//m_moveSpeed.x = Pad(0).GetLStickXF() * 250.0f;
	//m_moveSpeed.z = Pad(0).GetLStickYF() * 250.0f;

	//m_moveSpeed.y -= 20.0f;

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
	m_moveSpeed += cameraForward * lStick_y * 200.0f;	//奥方向への移動速度を加算。
	m_moveSpeed += cameraRight * lStick_x * 200.0f;		//右方向への移動速度を加算。

	//AnimationControl();

	m_position = m_charaCon.Execute(m_moveSpeed);

	m_skinModelRender->SetPosition(m_position);

	if (Pad(0).IsPress(enButtonA)) {
		Bullet* bullet = NewGO<Bullet>(0);
		//弾丸の座標にプレイヤーの座標を代入する。
		bullet->m_position = m_position;
		//Z軸方向に400の速度を設定する。
		bullet->m_moveSpeed.z = 400.0f;

	}
	


}//}Playerのモデルの位置を原点にするとラグが治るかも？