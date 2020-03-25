#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"

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
	
	bubble_position += bubble_movespeed;
	StopPosition(bubble_position, bubble_movespeed);

	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		{
			if (this != awa && awa->parent == NULL) {
				//泡が自分じゃなく、親がいないとき。
				CVector3 a_a_kyori = bubble_position - awa->bubble_position;
				//もしも、距離が一定値以下だったら。
				if (a_a_kyori.Length() <= 5.0) {
					awa->parent = this;
				}
			}

			return	true;

		}
		return false;
		});


	p_a_kyori = m_player->GetPosition() - GetPosition();
	p_a_kyori.Length();
	if (p_a_kyori.Length() <= 10)
	{
		DeleteGO(this);
	}
	Dess(bubble_position);
	bubble_skinmodelrender->SetPosition(bubble_position);
}