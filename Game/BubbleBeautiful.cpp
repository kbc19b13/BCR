#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "BubbleBeautiful.h"
#include "BubbleCluster.h"

BubbleBeautiful::BubbleBeautiful()
{

}

BubbleBeautiful::~BubbleBeautiful()
{

}

bool BubbleBeautiful::Start()
{
	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa_b.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());
	bubble_skinmodelrender->SetShadowCasterFlag(true);
	//すぺきゅらマップをロード。
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/b_awa_spec.dds");
	bubble_skinmodelrender->FindMaterial([&](CModelEffect* mat) {
		mat->SetSpecularMap(m_specMap.GetBody());
	});
	bubble_skinmodelrender->SetEmissionColor({ 0.2f, 0.2f, 0.1f });
	direction = rand() % 3;
	if (direction == 0) {
		bubble_movespeed.x = 3.0f;
		bubble_movespeed.Normalize();
	}
	else if (direction == 1) {
		bubble_movespeed.x = 1.0f;
		bubble_movespeed.Normalize();
	}
	else if (direction == 2) {
		bubble_movespeed.x = 0.5f;
		bubble_movespeed.Normalize();
	}

	//クラスターはゲーム終了時にまとめて削除しているので、デストラクタでは削除しない。
	m_bubbleCluster = NewGO<BubbleCluster>(0, "バブルクラスター");
	m_bubbleCluster->AddBubble(this);

	clean = true;

	return true;
}

void BubbleBeautiful::Update()
{
	/*
	きれいな泡をPlayerがわるとアイテムを落とす→Bulletの当たり判定
	{
	・スピードUP？
	・体力回復？
	・
	↑のアイテムをPlayerに追加
	2D画像(アイテム)の増加
*/
	
	UpdateCommon();
}
