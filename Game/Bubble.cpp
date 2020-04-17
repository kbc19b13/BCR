#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "Bullet.h"
#include "BubbleCluster.h"

Bubble::Bubble()
{
	isi = FindGO<BubbleCreator>("isi");
	
	
	m_player = Player::P_GetInstance();
}

bool Bubble::Start()
{
	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());
	bubble_skinmodelrender->SetShadowCasterFlag(true);
	//すぺきゅらマップをロード。
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/awa_spec.dds");
	bubble_skinmodelrender->FindMaterial([&](CModelEffect* mat) {
		mat->SetSpecularMap(m_specMap.GetBody());
	});
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

void Bubble::Update()
{
	
	

	oyako();

	awa_Delete();

	

	/*
	//弾と泡との当たり判定
	QueryGOs<Bullet>("awa", [&](Bullet* awa)->bool {
		//２点間の距離を計算する。
		CVector3 diff = awa->m_position - bubble_position;
		if (diff.Length() < 500.0f) {	//距離が500以下になったら。
			//prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			//ss->Init("sound/explosion.wav");	//explosion.wavをロード。
			//ss->SetVolume(0.05f);				//うるさいので音を小さくする。
			//ss->Play(false);					//ワンショット再生。
			DeleteGO(this);
			//falseを返したらクエリは終了。
			return false;
		}
		//trueを返したらクエリは継続。
		return true;
		});
	*/

	bubble_skinmodelrender->SetPosition(bubble_position);
}

//awaの親子関係
void Bubble::oyako()
{
	//泡をクラスターの移動速度で動かす（泡は動かない）
	bubble_position += m_bubbleCluster->GetMoveSpeed() + m_moveSpeedAdd;
	
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		if (awa == this) {
			return true;
		}
		if (awa->m_bubbleCluster == m_bubbleCluster) {
			//同じクラスター
			return true;
		}
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
		DeleteGO(m_bubbleCluster);
	}
}

void Bubble::Deth(float time)
{
	while (Crash) {
		
		DethTime -= GameTime().GetFrameDeltaTime();
		if (DethTime < 0.0f) {
			Crash = false;
		}

	}

}

