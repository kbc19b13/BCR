#include "stdafx.h"
#include "awa.h"
#include "Player.h"

awa::awa()
{

	m_awa = NewGO<prefab::CSkinModelRender>(0);
	m_awa->Init(L"modelData/awa.cmo");
	m_player = NewGO<Player>(0);

	m_player = Player::P_GetInstance();
}
awa::~awa()
{

	DeleteGO(m_awa);

}

void awa::Update()
{
	p_awa.z -= 10.0f;
	p_a_kyori = m_player->Getposition() - p_awa;
	p_a_kyori.Length();
	if (p_a_kyori.Length() <= 100)
	{
		DeleteGO(this);
	}
}