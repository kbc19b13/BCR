#include "stdafx.h"
#include "SceneSelect.h"
#include "Game1.h"
#include "Game2.h"

SceneSelect::SceneSelect()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"../Assets/sprite/SceneSelect.dds", 1280.0f, 720.0f);
}


SceneSelect::~SceneSelect()
{
	DeleteGO(m_spriteRender);
}

void SceneSelect::Update()
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