#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"
#include "isi.h"

Game1::Game1()
{

}


Game1::~Game1()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);
	DeleteGO(m_spriteRender);
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

	//クラスの作成
	m_isi = NewGO<isi>(0);
	m_player = NewGO<Player>(0, "doll");
	m_camera = NewGO<Camera>(0);

	////////////////////////////////////////////////////////

	//レベルを構築する。
	m_level.Init(L"level/kawa_le.tkl", [&](LevelObjectData& objData) {
		
		
			if (objData.EqualObjectName(L"isi") == true) {

				m_isi = NewGO<isi>(0, "isi[i]");
				m_isi->Setposition(objData.position);
				
				return true;
			}
			
		return false;
		});

	
	//		
	//	}

	//	if (p_i_leng.Length())//Lengthでベクトルの長さを取得
	//	{
	//		
	//		return false;
	//	}
	//	return	true;
	//	});
	
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

}