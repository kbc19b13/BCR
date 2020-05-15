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

	awa = FindGO<Bubble>("awa");
	
	return true;
}

void Bullet::Update()
{
	//弾丸を移動させる。
	m_position += m_moveSpeed;

		QueryGOs<Bubble>("bubble", [&](Bubble* bubble)->bool 
		{
			//泡と弾の２点間の距離を計算する。
			CVector3 diff = bubble->GetPosition() - m_position;
			//きれいな泡なら
			if (bubble->GetClean() == true) 
			{
				//アイテムの処理
				int item = rand() % 2;
				if ( item == 0 ){
 					game1->Gets_up() + 1;
				}
				if (item == 0) {
					game1->Gethp_up() + 1;
				}
			}
			//距離が50.0f以下になったら消す
			if (diff.Length() < 50.0f) 
			{	
				//弾数の減少

				DeleteGO(bubble);

				//クエリ終了。
				return false;
			}
		return true;
		});
		
	
	//タイマーを加算する。
	//m_timer++;
	if (m_timer >= 50) {
		//タイマーが50になったらインスタンスを削除する。
		DeleteGO(this);
	}

	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}
