#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "Bullet.h"

Bubble::Bubble()
{
	isi = FindGO<BubbleCreator>("isi");
	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());

	m_player = Player::P_GetInstance();
}
Bubble::~Bubble()
{

	DeleteGO(bubble_skinmodelrender);

}

void Bubble::Update()
{
	
	oyako();

	

	Kill(bubble_position);

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

	if (/*もしも親がいたら*/
		parent != nullptr) {
		bubble_position += parent->bubble_movespeed;
	}
	else {
		bubble_position += bubble_movespeed;
		StopPosition(bubble_position, bubble_movespeed);
	}
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		{
			if (this != awa					//検索のawaが自分じゃない
				&& parent != awa			//親とぶつかった場合は無視
				&& children.empty()			//empty = 空っぽ
				&& (parent == nullptr		//親がいない
					||						//かつ
					parent != awa->parent)	//検索出来たawaの親と一緒じゃない
				) {

				float rate = 0.5f;			//合体後の速度の調整？

	/////////////////////*親がいるかで処理を分ける*//////////////////////////

				/*両方とも親がいないときの重みは均等。*/
				if (parent == nullptr		//親がいない
					&& awa->parent == nullptr//検索出来たawaも親がいない
					) {
					
					rate = 0.5f;//

				}
				/*自分だけ親がいなくて、検索相手は親がいる。*/
				else if (parent == nullptr) {
					
					rate = (float)(awa->parent->children.size())			//親の子供の数を参照
							/												//割り算
							((float)awa->parent->children.size() + 2);		//親の子供の数を参照(+2？= サイズの拡張？)
					
					//return true; //デバッグ用スキップ機能
				}
				/*相手に親がいなくて、自分に親がいる。*/
				else if (awa->parent == nullptr) {
					
					rate = 1.0f / ((float)parent->children.size() + 2);

				}
				/*両方親がいる。*/
				else {
					//今の親のほうが勢力が大きい時に入る
					if (parent->children.size() >							//親の子供の数
						awa->parent->children.size()) {						//検索したawaの親の子供の数
						
						return true; //デバッグ用スキップ機能
					}
					rate = (float)awa->parent->children.size()									//検索したawaの親の子供の数
							/																	//割り算
							(float)(awa->parent->children.size() + parent->children.size());	//検索したawaの親の子供の数
				}																				//+親の子供の数
				rate = std::powf(rate, 0.7f);		//std::powf＝累乗

				/*泡が自分じゃなく、親がいないとき。*/
				CVector3 a_a_kyori = bubble_position - awa->bubble_position;		//awaとawaの距離を計算する
				//もしも、距離が一定値以下だったら。
				if (a_a_kyori.Length() <= 10.0) {
					Bubble* oldParent = parent;					//元の親を覚えておく。
					parent = awa;								//親を検索したawaにする
					while (parent->parent != nullptr) {			//親に親がいない
						parent = parent->parent;
					}
					if (oldParent != nullptr	//古い親がいない
						&& oldParent != parent	//新しい親と古い親が別物
						) {													
						for (Bubble* child : oldParent->children) {			//Bubbleポインタ型の　child　を設定 : 古い親の子供
							child->parent = parent;							//childの親を自分に書き換える
							parent->children.push_back(child);				//書き換えた親の配列を更新？
						}
						oldParent->children.clear();						//古い親の子供(配列)をクリア(掃除)？
						oldParent->parent = parent;							//古い親に自分に書き換える
						parent->children.push_back(oldParent);				//書き換えた親の配列を更新？
					}
					//親の子供に自分を登録する。
					parent->children.push_back(this);
					//移動速度を合成する。
					parent->bubble_movespeed.Lerp(rate, bubble_movespeed, parent->bubble_movespeed);
					//合体すると、下方向に速度を少し加える。
					parent->bubble_movespeed.z += Random().GetRandDouble() * 0.01f;
				}
			}

			return	true;

		}
		return false;
		});

}

//awaのDeleta処理
void Bubble::awa_Delete()
{
	/*
	awa検索
	距離を計算
	Playerとawaが当たったか調べる
	①あたったawaが親か調べる
	②あたったawaの親を調べる
	③あたったawaを消す

	①②
	親->子供(配列)を消す
	親を消す
	

	①②③
	PlayerのHPを減らす

	できたら連鎖させる
	*/

	//awaの検索
	QueryGOs<Bubble>("awa", [&](Bubble* awa)->bool {
		//距離を計算する
		CVector3 p_a_kyori = m_player->GetPosition() - awa->GetPosition();
		if (p_a_kyori.Length() <= 10.0f) {
			if (awa->parent != nullptr)
			{

				for (int i = 0; i > awa->parent->children.size(); i++)
				{
					DeleteGO(children[i]);
				}
					
			}
			//else
			//{
			//
			//}
			
			//PlayerのHPを減らす

			return false;
		}
		return true;
		});


}