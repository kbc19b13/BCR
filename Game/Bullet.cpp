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
	//弾丸を移動させる。
	m_position += m_moveSpeed;
	
	//タイマーを加算する。
	//m_timer++;
	if (m_timer >= 50) {
		//タイマーが50になったらインスタンスを削除する。
		DeleteGO(this);
	}

	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}
