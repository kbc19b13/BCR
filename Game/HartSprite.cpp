#include "stdafx.h"
#include "HartSprite.h"
#include "Game1.h"

HartSprit::HartSprit()
{
	
}

HartSprit::~HartSprit()
{
	DeleteGO(m_spriteRender[0]);
	DeleteGO(m_spriteRender[1]);
	DeleteGO(m_spriteRender[2]);
	DeleteGO(m_spriteRender[3]);
	DeleteGO(m_spriteRender[4]);
	DeleteGO(m_spriteRender[5]);
	DeleteGO(m_spriteRender[6]);
	DeleteGO(m_spriteRender[7]);
	DeleteGO(m_spriteRender[8]);
	DeleteGO(m_spriteRender[9]);
	//////////////////////////////////////
	DeleteGO(h_spriteRender[0]);
	DeleteGO(h_spriteRender[1]);
	DeleteGO(h_spriteRender[2]);
	DeleteGO(h_spriteRender[3]);
	DeleteGO(h_spriteRender[4]);
	DeleteGO(h_spriteRender[5]);
	DeleteGO(h_spriteRender[6]);
	DeleteGO(h_spriteRender[7]);
	DeleteGO(h_spriteRender[8]);
	DeleteGO(h_spriteRender[9]);
	DeleteGO(h_spriteRender[10]);
}

bool HartSprit::Start()
{

	/*ハート形*/
//スプライトを初期化。
	/*m_spriteRender[0] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[0]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[1] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[1]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[2] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[2]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[3] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[3]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[4] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[4]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[5] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[5]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[6] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[6]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[7] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[7]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[8] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[8]->Init(L"sprite/HPhartBar.dds", 50, 50);
	m_spriteRender[9] = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender[9]->Init(L"sprite/HPhartBar.dds", 50, 50);

	m_spriteRender[0]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[1]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[2]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[3]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[4]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[5]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[6]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[7]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[8]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[9]->SetPosition(m_position);
	m_position = m_position + add_position;*/

//////////////////////////////////////////////////////////////////

	h_spriteRender[0] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[0]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[1] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[1]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[2] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[2]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[3] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[3]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[4] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[4]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[5] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[5]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[6] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[6]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[7] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[7]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[8] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[8]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[9] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[9]->Init(L"sprite/HPhart.dds", 50, 50);
	h_spriteRender[10] = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender[10]->Init(L"sprite/HPhart.dds", 50, 50);
	
	//game1 = FindGO<Game1>("Game1");

	return true;
}

void HartSprit::Update()
{
	//c = game1->Geta();
	
	if (c > 10)
	{
		c = 10;
	}
	if (old != c)
	{
		b = 0;
		State = 0;
		old = c;
	}
	if (State == 0) {

		/*for (int i = 0; i > c; i++) {
			add_position = add_position + add_position;
		}*/
		h_position = h_position + add_position;
		
		h_spriteRender[b]->SetPosition(h_position);
		b++;
		
		if (b == old + 1)
		{
			State = 1;
		}
		
	}
}
