#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Camera.h"
#include "BackGround.h"

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
	DeleteGOs("バブルクラスター");
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
		if (objData.EqualObjectName(L"kawa")) {
			BackGround* kawa = NewGO<BackGround>(0, "kawa");
			kawa->Setposition(objData.position);

			return true;
		}
		//クラスの処理が入らない
		//レベル配置の通りに座標を配置する
		return false;
		});

	//ライトを設置。
	m_dirLig = NewGO<prefab::CDirectionLight>(0);
	//ライトの方向を計算。
	CVector3 dir = { 1, -1, 1 };
	dir.Normalize(); //方向は大きさ１である必要があるので正規化する。
	m_dirLig->SetDirection(dir);
	m_dirLig->SetColor({ 0.6f, 0.6f, 0.6f, 1.0f });	//真っ赤なライト。
	m_dirLig->SetLightingMaterialIDGroup(1 << enMaterialID_Default);
	LightManager().SetAmbientLight({ 0.2f, 0.2f, 0.2f });	//環境ライト

	shadow::DirectionShadowMap().SetLightDirection(dir);
	
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

	h_spriteRender->Init(L"sprite/hp.dds", s, 30);

	m_spriteRender->SetPosition(m_position);
	h_spriteRender->SetPosition(h_position);
	h_spriteRender->SetScale(scale);

}