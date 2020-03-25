#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "BubbleChange.h"


BubbleChange::BubbleChange()
{
	m_player = Player::P_GetInstance();
}

BubbleChange::~BubbleChange()
{
	DeleteGO(bubble2_skinmodelrender);
}

bool BubbleChange::Start()
{

	isi = FindGO<BubbleCreator>("isi");
	bubble2_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble2_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble2_skinmodelrender->SetPosition(isi->Getposition());

	direction = rand() % 3;
	if (direction == 0) {
		bubble2_movespeed.x = 3.0f;
	}
	else if (direction == 1) {
		bubble2_movespeed.x = 1.0f;
	}
	else if (direction == 2) {
		bubble2_movespeed.x = 0.5f;
	}

	return true;
}

void BubbleChange::Update()
{
	bubble2_position += bubble2_movespeed;

	StopPosition(bubble2_position, bubble2_movespeed);


	CVector3 p_a_kyori = m_player->GetPosition() - GetPosition();
	p_a_kyori.Length();
	if (p_a_kyori.Length() <= 10)
	{
		DeleteGO(this);
	}
	Dess(bubble2_position);
	bubble2_skinmodelrender->SetPosition(bubble2_position);

}

