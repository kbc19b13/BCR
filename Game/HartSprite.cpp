#include "stdafx.h"
#include "HartSprite.h"
bool Hartsprit::Start()
{
	/*ハート形*/
//スプライトを初期化。
	m_spriteRender[0] = NewGO<prefab::CSpriteRender>(0);
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

	m_spriteRender[0]->SetPosition(m_position);
	h_spriteRender[0]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[1]->SetPosition(m_position);
	h_spriteRender[1]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[2]->SetPosition(m_position);
	h_spriteRender[2]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[3]->SetPosition(m_position);
	h_spriteRender[3]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[4]->SetPosition(m_position);
	h_spriteRender[4]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[5]->SetPosition(m_position);
	h_spriteRender[5]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[6]->SetPosition(m_position);
	h_spriteRender[6]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[7]->SetPosition(m_position);
	h_spriteRender[7]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[8]->SetPosition(m_position);
	h_spriteRender[8]->SetPosition(m_position);
	m_position = m_position + add_position;
	m_spriteRender[9]->SetPosition(m_position);
	h_spriteRender[9]->SetPosition(m_position);
	m_position = m_position + add_position;

	return true;
}

void Hartsprit::Update()
{

}