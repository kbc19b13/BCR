#include "stdafx.h"
#include "isi.h"
#include "Player.h"
#include "awa.h"


isi::isi()
{

	m_player = Player::P_GetInstance();
	
}

isi::~isi()
{
	DeleteGO(skin_isi);
}

bool isi::Start()
{
	skin_isi = NewGO<prefab::CSkinModelRender>(0);

	skin_isi->Init(L"modelData/isi.cmo");

	
	m_awa->SetPosition(p_isi);
	
	return true;
}

void isi::Update()
{
	
	//Player‚Æisi‚Æ‚Ì’·‚³‚Åawa‚ð”­¶‚³‚¹‚é
	p_i_leng = p_isi - m_player->Getposition();
	if (p_i_leng.Length() <= 100.0f)//Length‚ÅƒxƒNƒgƒ‹‚Ì’·‚³‚ðŽæ“¾
	{
		timer++;
		if (timer >= 60)
		{
			state = rand() % 3;
			if (state == 0)
			{
				
				awa* m_awa = NewGO<awa>(0);
				m_awa->SetPosition(p_isi);

				timer = 0;
			}
			if (state == 1)
			{
				
				awa* m_awa = NewGO<awa>(0);
				m_awa->SetPosition(p_isi);

				timer = 0;
			}
			if (state == 2)
			{
				
				awa* m_awa = NewGO<awa>(0);
				m_awa->SetPosition(p_isi);

				timer = 0;
			}
		}
	}
}