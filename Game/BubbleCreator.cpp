#include "stdafx.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Bubble.h"
#include "BubbleChange.h"
#include "BubbleBeautiful.h"


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

	return true;
}

void BubbleCreator::Update()
{
	if (this == nullptr) { return; }

	//Player��isi�Ƃ̒�����awa�𔭐�������
	CVector3 p_i_leng = bc_position - m_player->GetPosition();
	if (p_i_leng.Length() <= 400.0f)//Length�Ńx�N�g���̒������擾
	{
		if (m_player->GetPosition().z > bc_position.z)
		{
			timer++;
			if (timer >= 100)
			{
				state = rand() % 9;
				if (state == 0 || state == 1 || state == 2 || state == 3 || state == 5 || state == 6)
				{
					BubbleChange* awa2 = NewGO<BubbleChange>(1, "awa");
					awa2->SetPosition(bc_position);

					//BubbleBeautiful* awa3 = NewGO<BubbleBeautiful>(0, "awa");
					//awa3->SetPosition(bc_position);

					timer = 0;
				}
				if (state == 7 || state == 8)
				{

					Bubble* awa = NewGO<Bubble>(1, "awa");
					awa->SetPosition(bc_position);

					timer = 0;
				}
				if (state == 4)
				{

					BubbleBeautiful* awa3 = NewGO<BubbleBeautiful>(1, "awa");
					awa3->SetPosition(bc_position);

					timer = 0;
				}
			}
		}
	}
}