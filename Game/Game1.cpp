#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"
#include "isi.h"

Game1::Game1()
{
	//�J������ݒ�B
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();


	//m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//m_skinModelRender->Init(L"modelData/kawa.cmo");
	m_player = NewGO<Player>(0, "doll");
	m_camera = NewGO<Camera>(0);

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
	//���x�����\�z����B
	m_level.Init(L"level/kawa_le.tkl", [&](LevelObjectData& objData) {

		if (objData.EqualObjectName(L"isi") == true) {

			m_isi = NewGO<isi>(0, "isi");
			m_isi->lep_isi = objData.position;
			return true;
		}

		return false;
		});


	//�X�v���C�g���������B
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/hp_bar.dds", 300, 50);


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