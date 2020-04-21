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

	/*
	QueryGOs<Bubble>("bubble", [&](Bubble* bubble)->bool {
		//２点間の距離を計算する。
		CVector3 diff = bubble->GetPosition() - m_position;
		if (bubblet->GetClean() == true) {
		//アイテムの処理

		}
		if (diff.Length() < 50.0f) {	//距離が50.0f以下になったら。
		//弾数の減少

			DeleteGO(bubble);

			//クエリ終了。
			return false;
		}
		return true;
		});
	*/	
	
	//タイマーを加算する。
	//m_timer++;
	if (m_timer >= 50) {
		//タイマーが50になったらインスタンスを削除する。
		DeleteGO(this);
	}

	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}
