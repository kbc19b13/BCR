#include "stdafx.h"
#include "Title.h"
#include "SceneSelect.h"

Title::Title()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"../Assets/sprite/title.dds", 1280.0f, 720.0f);
}


Title::~Title()
{
	DeleteGO(m_spriteRender);
}

void Title::Update()
{
	if (Pad(0).IsPress(enButtonX)) {
		NewGO<SceneSelect>(0);
		DeleteGO(this);
	}
}