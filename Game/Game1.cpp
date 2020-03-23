#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Camera.h"

Game1* Game1::m_instance = nullptr;

Game1::Game1()
{

	//インスタンスの制限
	if (m_instance != nullptr)
	{
		std::abort();
	}

	m_instance = this;
}


Game1::~Game1()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);
	DeleteGO(m_spriteRender);
	DeleteGO(h_spriteRender);

	m_instance = nullptr;
}

bool Game1::Start()
{
	/////////////////////////////////////////////////////////

	//確認のawa
	m_skin = NewGO<prefab::CSkinModelRender>(0);
	m_skin->Init(L"modelData/awa.cmo");
	m_skin->SetPosition(pos);

	//スプライトを初期化。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/hp_bar.dds", 300, 50);

	h_spriteRender = NewGO<prefab::CSpriteRender>(0);
	h_spriteRender->Init(L"sprite/hp.dds", 285, 30);

	//クラスの作成
	m_player = NewGO<Player>(0, "doll");
	m_camera = NewGO<Camera>(0);
	

	////////////////////////////////////////////////////////

	//レベルを構築する。
	m_level.Init(L"level/kawa_le.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"isi")) {

			BubbleCreator* isi = NewGO<BubbleCreator>(0, "isi");
			isi->Setposition(objData.position);

			return true;
		}
		//クラスの処理が入らない
		//レベル配置の通りに座標を配置する
		return false;
		});

	return true;
}

void Game1::Update()
{
	

	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<SceneSelect>(0);
		DeleteGO(this);
	}
	if (Pad(0).IsPress(enButtonStart)) {
		NewGO<Title>(0);
		DeleteGO(this);
	}

	m_spriteRender->SetPosition(m_position);
	h_spriteRender->SetPosition(h_position);

}