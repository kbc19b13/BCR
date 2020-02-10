#include "stdafx.h"
#include "Title.h"
#include "Game1.h"
#include "Game2.h"

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
	if (Pad(0).IsPress(enButtonA)) {
		NewGO<Game1>(0, "Game1");
		DeleteGO(this);
	}
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<Game2>(0, "Game2");
		DeleteGO(this);
	}
}