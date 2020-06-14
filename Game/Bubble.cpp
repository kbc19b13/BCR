#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "Bullet.h"
#include "BubbleCluster.h"
#include "HartSprite.h"
#include "Game1.h"

Bubble::Bubble()
{
	isi = FindGO<BubbleCreator>("isi");
	
	
	m_player = Player::P_GetInstance();

	
}

bool Bubble::Start()
{
	///////////すぺきゅらマップ.気にしない/////////////////////////////

	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());
	bubble_skinmodelrender->SetShadowCasterFlag(true);
	//すぺきゅらマップをロード。
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/awa_spec.dds");
	bubble_skinmodelrender->FindMaterial([&](CModelEffect* mat) {
		mat->SetSpecularMap(m_specMap.GetBody());
	});

	/////////////////////////////////////////////////////////////////////

	//クラスターはゲーム終了時にまとめて削除しているので、デストラクタでは削除しない。
	m_bubbleCluster = NewGO<BubbleCluster>(0, "バブルクラスター");
	m_bubbleCluster->AddBubble(this);

	
	////////////////////////////////////////////
	/*少しだけ動きをランダムに
	　直線的な動きでなく流動的な動きにする*/
	m_moveSpeedAdd.x = Random().GetRandDouble();
	if (Random().GetRandInt() % 2 == 0) {
		m_moveSpeedAdd.x *= -1.0f;
	}
	m_moveSpeedAdd.z = Random().GetRandDouble();

	m_moveSpeedAdd *= 0.05f;
	////////////////////////////////////////////
	

	//泡のサイズをちょっとずつ変える
	float a = (120 + (rand() % 24 + 1)) / 120.0f ;
	CVector3 scale = { a, a, a };
	bubble_skinmodelrender->SetScale(scale);

	
	return true;
}

Bubble::~Bubble()
{

	DeleteGO(bubble_skinmodelrender);

}

//更新処理の共通処理
void Bubble::UpdateCommon()
{
	switch (m_state)
	{
		//通常処理
	case State_Normal:

		oyako();
		//PlayerとBubbleの当たり判定
		awa_Delete();

		QueryGOs<Bullet>("tama", [&](Bullet* tama)
		{

			//泡と弾の２点間の距離を計算する。
			CVector3 diff = bubble_position - tama->GetPosition();

			

			//距離が50.0f以下になったら消す
			if (diff.Length() < 10.0f)
			{
				
				
				DeadState = 2;



				//きれいな泡なら
				/*if (clean == true)
				{

					if (game1->Getitem_State() == 0) {
						game1->Setitem_State(1);
					}

				}*/

				DeleteGO(m_bubbleCluster);

				//クエリ終了。
				return false;
			}
			return true;
		});

		bubble_skinmodelrender->SetPosition(bubble_position);
		break;

		//死亡リクエストが来ているときの処理
	case State_RequestDead:
		
		

		m_deadTimer -= 0.05f;
		Deathscale += Deathscale * 0.005;
		if (Deathscale.x <  1.35f && Deathscale.y < 1.35f && Deathscale.z < 1.35f ) {
			//スケールを大きくする
			bubble_skinmodelrender->SetScale(Deathscale);
		}
		
		if (m_deadTimer < 0.0f ) {
			//タイマーが0以下になったので死亡。
			/*if (clean == true)
			{
				
				if (game1->Getitem_State() == 0) {
					game1->Setitem_State(2);
				}
			}*/
			//エフェクト再生
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/aw.efk");
			effect->SetPosition(bubble_position);
			//大きく
			float scale = 2.0f;
			effect->SetScale({ scale,scale,scale });

			if (DeadState == 2) {
				/*m_player->SetBubbleExplosionPlus(m_player->GetBubbleExplosion());*/
				m_player->BubbleExplosion++;
			}
			if (DeadState == 1) {
				/*m_player->SetBubbleExplosionMinus(m_player->GetBubbleExplosion());*/
				m_player->BubbleExplosion--;
			}

			DeleteGO(this);
		}
		

		break;
	}
}

void Bubble::Update()
{
	UpdateCommon();	
}

//awaの親子関係
void Bubble::oyako()
{
	//泡をクラスターの移動速度で動かす（泡は動かない）
	bubble_position += m_bubbleCluster->GetMoveSpeed() + m_moveSpeedAdd;
	
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		////////////////////////////////////////////////////////////////////
		if (awa == this || awa->StateIsRequestDead()) {		//死亡している
			return true;
		}
		if (awa->m_bubbleCluster == m_bubbleCluster) {		//同じクラスター
			return true;
		}
		///////////////////////////////////////////////////////////////////

		//距離で消す
		CVector3 a_a_kyori = bubble_position - awa->bubble_position;		//awaとawaの距離を計算する
		//もし、距離が一定値以下だったら消す
		if (a_a_kyori.Length() <= 10.0) {
			
			//クラスターを合成する。
			auto oldCluster = awa->m_bubbleCluster;
			m_bubbleCluster->CombineCluster(awa->m_bubbleCluster);
			
			//古いのクラスターを削除。
			DeleteGO(oldCluster);
		}
		return true;
	});
}

//awaの攻撃、Deleta処理
void Bubble::awa_Delete()
{
	CVector3 p_a_kyori = m_player->GetPosition() - bubble_position;
	if (p_a_kyori.Length() <= 10.0f) {

		//Playerの体力減少！！
		
		DeadState = 1;

		DeleteGO(m_bubbleCluster);
	}
	if (m_player->GetPosition().z < bubble_position.z - 50.0f)
	{
		DeadState = 0;	

		DeleteGO(m_bubbleCluster);
	}

}


