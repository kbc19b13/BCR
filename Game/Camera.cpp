#include "stdafx.h"
#include "Camera.h"
#include "Player.h"

Camera::Camera()
{
}


Camera::~Camera()
{
}

bool Camera::Start()
{
	//注視点から視点までのベクトルを設定。
	m_toCameraPos.Set(0.0f, 30.0f,10.0f);
	//プレイヤーのインスタンスを探す。
	m_player = FindGO<Player>("doll");

	//カメラのニアクリップとファークリップを設定する。
	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(20000.0f);

	return true;
}

void Camera::Update()
{
	//注視点を計算。
	CVector3 target = m_player->GetPosition();
	target.y += 100.0f;

	//視点を計算する。
	CVector3 pos = target + m_toCameraPos;
	//メインカメラに注視点と視点を設定する。
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);

	//カメラの更新。
	MainCamera().Update();
}