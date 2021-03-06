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

	m_moveSpeed -= m_moveSpeed * 0.005f;
	
	//タイマーを加算する。
	m_timer++;
	if (m_timer >= 60 || 
		m_moveSpeed.x < 0.0f && m_moveSpeed.y < 0.0f && m_moveSpeed.z < 0.0f ||
		m_position.x > 95.0f ||
		m_position.x < -95.0f) {
		//タイマーが50になったらインスタンスを削除する。
		/*s_effect = NewGO<prefab::CSoundSource>(0);
		s_effect->Init(L"sound/pasha.wav");
		s_effect->Play(false);*/
		DeleteGO(this);
	}

	

	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}

