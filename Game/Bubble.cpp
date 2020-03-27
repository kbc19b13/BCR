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

	//Playerとawaの当たり判定
	/*p_a_kyori = m_player->GetPosition() - GetPosition();
	p_a_kyori.Length();
	if (p_a_kyori.Length() <= 10)
	{
		DeleteGO(this);
	}*/
//	Dess(bubble_position);


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
			if (this != awa
				&& parent != awa			//親とぶつかった場合は無視
				&& children.empty()
				&& (parent == nullptr || parent != awa->parent)
				) {
				float rate = 0.5f;
				if (parent == nullptr && awa->parent == nullptr) {
					//両方とも親がいないときの重みは均等。
				//	rate = 0.5f;
				}
				else if (parent == nullptr) {
					//自分だけ親がいなくて、相手は親がいる。
					rate = (float)(awa->parent->children.size()) / ((float)awa->parent->children.size() + 2);
					//return true;
				}
				else if (awa->parent == nullptr) {
					//相手に親がいなくて、自分に親がいる。
					rate = 1.0f / ((float)parent->children.size() + 2);
				}
				else {
					//両方親がいる。
					if (parent->children.size() > awa->parent->children.size()) {
						//今の親のほうが勢力が大きい。
						return true;
					}
					rate = (float)awa->parent->children.size() / (float)(awa->parent->children.size() + parent->children.size());
				}

				rate = std::powf(rate, 0.7f);
				//泡が自分じゃなく、親がいないとき。
				CVector3 a_a_kyori = bubble_position - awa->bubble_position;
				//もしも、距離が一定値以下だったら。
				if (a_a_kyori.Length() <= 10.0) {
					//元の親を覚えておく。
					Bubble* oldParent = parent;
					parent = awa;
					while (parent->parent != nullptr) {
						parent = parent->parent;
					}
					if (oldParent != nullptr	//古い親がいる
						&& oldParent != parent	//新しい親と古い親が別物
						) {
						for (Bubble* child : oldParent->children) {
							child->parent = parent;
							parent->children.push_back(child);
						}
						oldParent->children.clear();
						oldParent->parent = parent;
						parent->children.push_back(oldParent);
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


	//QueryGOs<Bullet>("awa", [&](Bullet* awa)->bool {
	//	//２点間の距離を計算する。
	//	CVector3 diff = awa->m_position - bubble_position;
	//	if (diff.Length() < 500.0f) {	//距離が500以下になったら。
	//		//prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
	//		//ss->Init("sound/explosion.wav");	//explosion.wavをロード。
	//		//ss->SetVolume(0.05f);				//うるさいので音を小さくする。
	//		//ss->Play(false);					//ワンショット再生。
	//		DeleteGO(this);						
	//		//falseを返したらクエリは終了。
	//		return false;
	//	}
	//	//trueを返したらクエリは継続。
	//	return true;
	//	});

}