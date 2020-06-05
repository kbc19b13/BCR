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
	m_moveSpeed -= m_moveSpeed * 0.02f;

	//弾丸を移動させる。
	m_position += m_moveSpeed;
	
	//タイマーを加算する。
	m_timer++;
	if (m_timer >= 50 || 
		m_moveSpeed.x < 0.0f && m_moveSpeed.y < 0.0f && m_moveSpeed.z < 0.0f ||
		m_position.x > 95.0f ||
		m_position.x < -95.0f) {
		//タイマーが50になったらインスタンスを削除する。
		DeleteGO(this);
	}

	//弾薬
	if (amo >= 0) {
		//弾薬が0になったら、
		//リロードのアニメーションをながして
		//アニメーションの再生中は弾を打てないようにする
		//弾薬を5追加する。

		amo += 5;

	}

	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}
