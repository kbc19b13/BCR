#include "stdafx.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Bubble.h"
#include "BubbleChange.h"


BubbleCreator::BubbleCreator()
{

	m_player = Player::P_GetInstance();

}

BubbleCreator::~BubbleCreator()
{
	DeleteGO(isi_skinmodelrender);
}

bool BubbleCreator::Start()
{
	isi_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);

	isi_skinmodelrender->Init(L"modelData/isi.cmo");

	isi_skinmodelrender->SetPosition(bc_position);

	//awa->SetPosition(bc_position);

	return true;
}

void BubbleCreator::Update()
{

	//Player‚Æisi‚Æ‚Ì’·‚³‚Åawa‚ð”­¶‚³‚¹‚é
	CVector3 p_i_leng = bc_position - m_player->GetPosition();
	if (p_i_leng.Length() <= 200.0f)//Length‚ÅƒxƒNƒgƒ‹‚Ì’·‚³‚ðŽæ“¾
	{
		timer++;
		if (timer >= 120)
		{
			state = rand() % 2;
			if (state == 0)
			{

				BubbleChange* awa2 = NewGO<BubbleChange>(0, "awa");
				awa2->SetPosition(bc_position);

				timer = 0;
			}
			if (state == 1)
			{

				Bubble* awa = NewGO<Bubble>(0, "awa");
				awa->SetPosition(bc_position);
				
				timer = 0;
			}
			if (state == 2)
			{

				Bubble* awa = NewGO<Bubble>(0, "awa");
				awa->SetPosition(bc_position);
				
				timer = 0;
			}
		}
	}
}