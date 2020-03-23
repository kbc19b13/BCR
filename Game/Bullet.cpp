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
	//弾丸を移動させる。
	m_position += m_moveSpeed;
	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
	//タイマーを加算する。
	m_timer++;
	if (m_timer == 50) {
		//タイマーが50になったらインスタンスを削除する。
		DeleteGO(this);
	}

}
