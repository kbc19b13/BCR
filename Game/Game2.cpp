#include "stdafx.h"
#include "Game2.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "Player.h"
#include "Camera.h"

//Game2* Game2::m_instance = nullptr;

Game2::Game2()
{
	////インスタンスの制限
	//if (m_instance != nullptr)
	//{
	//	std::abort();
	//}

	////確認のawa
	//m_skin = NewGO<prefab::CSkinModelRender>(0);
	//m_skin->Init(L"modelData/awa.cmo");
	//m_skin->SetPosition(pos);



	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/kawa.cmo");

	//m_player = NewGO<Player>(0, "doll");
	//m_camera = NewGO<Camera>(0);

	//m_instance = this;
}


Game2::~Game2()
{
	/*DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);
	DeleteGO(m_spriteRender);
	DeleteGO(h_spriteRender);
	DeleteGOs("バブルクラスター");

	m_instance = nullptr;*/
}

bool Game2::Start()
{
	////スプライトを初期化。
	//m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//m_spriteRender->Init(L"sprite/HPhartBar.dds", 50, 50);

	//h_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//h_spriteRender->Init(L"sprite/HPhart.dds", 50, 50 );


	return true;
}

void Game2::Update()
{

	/*if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<SceneSelect>(0);
		DeleteGO(this);
	}
	if (Pad(0).IsPress(enButtonStart)) {
		NewGO<Title>(0);
		DeleteGO(this);
	}

	m_spriteRender->SetPosition(m_position);
	h_spriteRender->SetPosition(h_position);*/

}