#include "stdafx.h"
#include "ResultScene.h"
#include "Title.h"
#include "Game1.h"
#include "Player.h"

ResultScene::ResultScene()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"../Assets/sprite/mh3.dds", 1280.0f, 720.0f);
	
	m_player = Player::P_GetInstance();

	/*gekiha = m_player->GetBubbleExplosion();*/
	defeat = NewGO<prefab::CFontRender>(0, "defeat");
	defeat->SetText(L"撃破数");
	defeat->SetPosition(defeat_position);
	/*defeat->SetColor(color);
	
	defeat->SetScale(scale);*/

	//最終撃破数の表示
	score = NewGO<prefab::CFontRender>(0, "score");
	wchar_t name[256];
	swprintf(name, L"%d", /*gekiha*/ m_player->BubbleExplosion);
	score->SetText(name);
	score->SetPosition(score_position);

	//サウンド再生
	buku = NewGO<prefab::CSoundSource>(0);
	buku->Init(L"sound/buku.wav");
	buku->Play(false);

	/*score->SetColor(color);
	
	score->SetScale(s_scale);*/
}

ResultScene::~ResultScene()
{
	DeleteGO(m_spriteRender);
	DeleteGO(defeat);
	DeleteGO(score);
}

void ResultScene::Update()
{
	
	//defeatの座標を反映させる
	defeat->SetPosition(defeat_position);

	//scoreの座標を反映させる
	score->SetPosition(score_position);

	if (Pad(0).IsTrigger(enButtonSelect)) {

		NewGO<Title>(0);
		
		//削除
		DeleteGO(this);
	}
}