#include "stdafx.h"
#include "isi.h"
#include "Player.h"


isi::isi()
{

	
	//m_player = FindGO<Player>("player");
}

isi::~isi()
{}

bool isi::Start()
{
	skin_isi = NewGO<prefab::CSkinModelRender>(0);

	skin_isi->Init(L"modelData/isi.cmo");

	skin_isi->SetPosition(p_isi);
	
	return true;
}

void isi::Update()
{
	timer++;

	//p_i_leng = m_player->m_position - lep_isi;

	if (timer >= 60)
	{
		state = rand() % 3;
		if(state == 0)
		{
			skin_awa = NewGO<prefab::CSkinModelRender>(0);
			skin_awa->Init(L"modelData/awa.cmo");
			skin_awa->SetPosition(p_isi);

			//timer = 0;
		}
		if (state == 1)
		{

			skin_awa = NewGO<prefab::CSkinModelRender>(0);
			skin_awa->Init(L"modelData/awa.cmo");
			skin_awa->SetPosition(p_isi);

			//timer = 0;
		}
		if (state == 2)
		{
			skin_awa = NewGO<prefab::CSkinModelRender>(0);
			skin_awa->Init(L"modelData/awa.cmo");
			skin_awa->SetPosition(p_isi);

			//timer = 0;
		}
	}
}