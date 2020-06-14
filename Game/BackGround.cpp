#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(){}

BackGround::~BackGround() {
	DeleteGO(bg_skinModelRender);
}

bool BackGround::Start() {

	bg_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	bg_skinModelRender->Init(L"modelData/kawa.cmo");
	bg_skinModelRender->SetShadowReceiverFlag(false);
	bg_skinModelRender->SetShadowCasterFlag(true);
	//すぺきゅらマップをロード。
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/water_spec.dds");
	bg_skinModelRender->FindMaterial([&](CModelEffect* mat) {
		mat->SetMaterialID(enMaterialID_Default);
		mat->SetSpecularMap(m_specMap.GetBody());
	});
	return true;
}

void BackGround::Update() {

}