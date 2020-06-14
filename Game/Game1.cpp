#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Camera.h"
#include "BackGround.h"
#include "Hartsprite.h"
#include "ResultScene.h"

Game1* Game1::m_instance = nullptr;

Game1::Game1()
{

	//�C���X�^���X�̐���
	if (m_instance != nullptr)
	{
		std::abort();
	}

	m_instance = this;

}


Game1::~Game1()
{
	m_instance = nullptr;
}

bool Game1::Start()
{

	//�N���X�̍쐬
	m_player = NewGO<Player>(0, "doll");
	m_camera = NewGO<Camera>(0);
	

	////////////////////////////////////////////////////////

	//���x�����\�z����B
	m_level.Init(L"level/kawa_le.tkl", [&](LevelObjectData& objData) {
		//�I�u�W�F�N�g������
		if (objData.EqualObjectName(L"isi")) {

			BubbleCreator* isi = NewGO<BubbleCreator>(2, "isi");
			isi->Setposition(objData.position);

			

			return true;
		}
		//�I�u�W�F�N�g������
		if (objData.EqualObjectName(L"kawa")) {
			BackGround* kawa = NewGO<BackGround>(0, "kawa");
			kawa->Setposition(objData.position);
			

			return true;
		}
		
		//�N���X�̏���������Ȃ�
		//���x���z�u�̒ʂ�ɍ��W��z�u����
		return false;
		});

	//////////////////////////////////////////////////////////////////////////////////

	//���C�g��ݒu�B
	m_dirLig = NewGO<prefab::CDirectionLight>(0);
	//���C�g�̕������v�Z�B
	CVector3 dir = { 1, -1, 1 };
	dir.Normalize(); //�����͑傫���P�ł���K�v������̂Ő��K������B
	m_dirLig->SetDirection(dir);
	m_dirLig->SetColor({ 0.6f, 0.6f, 0.6f, 1.0f });	//�^���Ԃȃ��C�g�B
	m_dirLig->SetLightingMaterialIDGroup(1 << enMaterialID_Default);
	LightManager().SetAmbientLight({ 0.2f, 0.2f, 0.2f });	//�����C�g

	shadow::DirectionShadowMap().SetLightDirection(dir);
	
	/////////////////////////////////////////////////////////////////////////////
	
	BGM = NewGO<prefab::CSoundSource>(0);
	BGM->Init(L"sound/kawaBGM.wav");
	BGM->Play(true);
	BGM2 = NewGO<prefab::CSoundSource>(0);
	BGM2->Init(L"sound/pop.wav");
	BGM2->Play(true);

	//HartSprit* m_hsp = NewGO<HartSprit>(0, "hsp");
	
	return true;
}

void Game1::OnDestroy()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);

	DeleteGO(BGM);
	DeleteGO(BGM2);

	/*DeleteGO(Capa);
	DeleteGO(Reco);
	DeleteGO(Prot);*/

	
	DeleteGO(m_dirLig);

	/*DeleteGO(Recovery);
	DeleteGO(Protection);
	DeleteGO(h_spriteRender);
	DeleteGO("hsp");*/
	
	DeleteGOs("�o�u���N���X�^�[");
	DeleteGO("kawa");
	DeleteGOs("isi");
}

void Game1::Update()
{
	/*
	if (item_State == 2) {
		if (Item_State == 0) {
			DeleteGO(Capa);
		}
		else if (Item_State == 1) {
			DeleteGO(Reco);
		}
		else if (Item_State == 2) {
			DeleteGO(Prot);
		}
		item_State = 0;
	}
	if (item_State == 1) {
		//�A�C�e���̏���
		int item = rand() % 3;
		if (item == 0)
		{
			CapaUp();
		}
		else if (item == 1)
		{
			Recovery();
		}
		else if (item == 2)
		{
			Protection();
		}
		
		item_State = 0;
	}
	*/
	if (m_player->GetPosition().z < -1000.0f)
	{
		NewGO<ResultScene>(0);
		DeleteGO(this);
	}

	if (Pad(0).IsTrigger(enButtonStart)) {
		NewGO<ResultScene>(0);
		DeleteGO(this);
	}

}



/*
void Game1::CapaUp()
{
	Capa = NewGO<prefab::CFontRender>(0, "Capa");
	Capa->SetText(L"�e�̗e�ʂ�����������I");
	Capa->SetColor(color);
	Capa->SetPosition(Gc_position);
	Capa->SetScale(scale);
	int b_capa = m_player->GetCapa();

	m_player->SetCapa(b_capa + 5);

	Item_State = 0;
}


void Game1::Recovery()
{
	Reco = NewGO<prefab::CFontRender>(0, "Reco");
	Reco->SetText(L"�̗�1�񕜂���I");
	Reco->SetColor(color);
	Reco->SetPosition(Gc_position);
	Reco->SetScale(scale);

	//a++;

	Item_State = 1;
}

void Game1::Protection()
{
	Prot = NewGO<prefab::CFontRender>(0, "Prot");
	Prot->SetText(L"���G����I");
	Prot->SetColor(color);
	Prot->SetPosition(Gc_position);
	Prot->SetScale(scale);

	Item_State = 2;
}
*/