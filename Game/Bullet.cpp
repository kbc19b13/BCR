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

		QueryGOs<Bubble>("awa", [&](Bubble* awa)->bool 
		{
			
			//泡と弾の２点間の距離を計算する。
			CVector3 diff = awa->GetPosition() - m_position;
			//きれいな泡なら
			//if (awa->GetClean() == true) 
			//{
			//	//アイテムの処理
			//	int item = rand() % 2;
			//	if ( item == 0 ){
 		//			game1->Gets_up() + 1;
			//	}
			//	if (item == 0) {
			//		game1->Gethp_up() + 1;
			//	}
			//}
			//距離が50.0f以下になったら消す
			if (diff.Length() < 10.0f) 
			{	
				//弾数の減少

				DeleteGO(awa);

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
