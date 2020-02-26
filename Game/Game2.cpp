#include "stdafx.h"
#include "Game2.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"

Game2::Game2()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/kawa.cmo");

	//確認のawa
	m_skin = NewGO<prefab::CSkinModelRender>(0);
	m_skin->Init(L"modelData/awa.cmo");
	m_skin->SetPosition(pos);

	m_player = NewGO<Player>(0, "doll");
	m_camera = NewGO<Camera>(0);


}


Game2::~Game2()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);
}


void Game2::Update()
{

	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<SceneSelect>(0);
		DeleteGO(this);
	}
	if (Pad(0).IsPress(enButtonStart)) {
		NewGO<Title>(0);
		DeleteGO(this);
	}

}