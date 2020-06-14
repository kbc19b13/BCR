#include "stdafx.h"
#include "Title.h"
#include "Game1.h"
#include "ResultScene.h"

Title::Title()
{
	//背景
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"../Assets/sprite/mizu.dds", 1280.0f, 720.0f);
	//タイトル
	m_spriteRender2 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender2->Init(L"../Assets/sprite/bubblecrusher.dds", 900.0f, 400.0f);
	m_spriteRender2->SetPosition(taiki_position);
	//演出
	m_spriteRender3 = NewGO<prefab::CSpriteRender>(0, "awa2D");
	m_spriteRender3->Init(L"../Assets/sprite/b2_leyer.dds", 50.0f, 50.0f);
	//スタート
	m_spriteRender4 = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender4->Init(L"../Assets/sprite/BubbleStart.dds", 600.0f, 400.0f);
	m_spriteRender4->SetPosition(taiki_position);

	BGM = NewGO<prefab::CSoundSource>(0, "BGM");
	BGM->Init(L"sound/kawaBGM.wav");
	BGM->Play(true);

	BGM2 = NewGO<prefab::CSoundSource>(0, "BGM2");
	BGM2->Init(L"sound/pop.wav");
	
}


Title::~Title()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_spriteRender2);
	DeleteGO(m_spriteRender3);
	DeleteGO(m_spriteRender4);
	if (BGM != nullptr) {
		DeleteGO(BGM);
	}
	DeleteGO(BGM2);

}

void Title::Update()
{
	if (Delete_State == 0) {
		t++;
		if (t > 20) {
			m_moveSpeedAdd.x = Random().GetRandDouble();
			if (Random().GetRandInt() % 20 != 0) {
				m_moveSpeedAdd.x *= -1.0f;
			}
			m_moveSpeedAdd.z = Random().GetRandDouble();

			m_moveSpeedAdd *= 5.5f;

			t = 0;
		}

		a_position += m_MoveSpeed + m_moveSpeedAdd;

		m_Scale += m_Scale * 0.005;

		m_spriteRender3->SetScale(m_Scale);
		m_spriteRender3->SetPosition(a_position);

		if (a_position.x < 0.0f)
		{
			DeleteGO(m_spriteRender3);
			m_spriteRender3 = nullptr;
			Delete_State = 1;

			DeleteGO(BGM);
			BGM = nullptr;
			State = 1;
		}

		if (Pad(0).IsTrigger(enButtonStart)) {
			NewGO<Game1>(0);
			DeleteGO(this);
		}

		if (State == 1)
		{
			BGM2->Play(true);

			if (s_Scale.x >= 1.0f) {
				size = -0.005f;
				jump = 0.5f;
			}
			if (s_Scale.x <= 0.8f) {
				size = 0.005f;
				jump = -0.5f;
			}
			s_Scale += s_Scale * size;
			s_position.y += jump;
			m_spriteRender4->SetScale(s_Scale);
			m_spriteRender4->SetPosition(s_position);
			m_spriteRender2->SetPosition(m_position);
		}
	}
		if (Delete_State == 1)
		{




			if (Pad(0).IsTrigger(enButtonStart))
			{

				NewGO<Game1>(0);
				DeleteGO(this);
			}

			if (State == 1)
			{
				BGM2->Play(true);

				if (s_Scale.x >= 1.0f) {
					size = -0.005f;
					jump = 0.5f;
				}
				if (s_Scale.x <= 0.8f) {
					size = 0.005f;
					jump = -0.5f;
				}
				s_Scale += s_Scale * size;
				s_position.y += jump;
				m_spriteRender4->SetScale(s_Scale);
				m_spriteRender4->SetPosition(s_position);
				m_spriteRender2->SetPosition(m_position);
			}
		}

}