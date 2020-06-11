#include "stdafx.h"
#include "Game1.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Title.h"
#include "SceneSelect.h"
#include "BubbleCreator.h"
#include "Player.h"
#include "Camera.h"
#include "BackGround.h"
#include "Hartsprite.h"

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
	DeleteGO(m_skinModelRender);
	DeleteGO(m_player);
	DeleteGO(m_camera);

	
	
	

	//DeleteGO(h_spriteRender);
	DeleteGOs("�o�u���N���X�^�[");
	m_instance = nullptr;
}

bool Game1::Start()
{

	/*
	HartSprit* hsp = NewGO<HartSprit>(0, "hsp");

	hsp->Seta(10);
	*/

/*
	//�̗̓o�[�^//

	//HP�o�[�g�̃X�v���C�g���������B
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/hp_bar.dds", 300, 50);
	//HP�o�[�̃X�v���C�g��������
	h_spriteRender = NewGO<prefab::CSpriteRender>(0);
*/

	
	
	//�A�C�e���̃X�v���C�g���������B
	//hp_up_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//hp_up_spriteRender->Init(L"sprite/.dds", 300, 50);


	//�N���X�̍쐬
	Player* m_player = NewGO<Player>(0, "doll");
	Camera* m_camera = NewGO<Camera>(0);
	

	////////////////////////////////////////////////////////

	//���x�����\�z����B
	m_level.Init(L"level/kawa_le.tkl", [&](LevelObjectData& objData) {
		//�I�u�W�F�N�g������
		if (objData.EqualObjectName(L"isi")) {

			BubbleCreator* isi = NewGO<BubbleCreator>(0, "isi");
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
	return true;
}

void Game1::Update()
{

	for (int i = 0; i > s_up; i++)
	{

		s_up_spriteRender[i] = NewGO<prefab::CSpriteRender>(0);
		s_up_spriteRender[i]->Init(L"sprite/hp_bar.dds", 300, 50);
		s_up_position.x += i * 10;
		s_up_spriteRender[i]->SetPosition(s_up_position);

	}

	/*
	//�A�C�e���g�p
	//if���Ŏg�p�̔��聕�f�N�������g����
	s_up--;
	*/


	if (Pad(0).IsPress(enButtonSelect)) {
		NewGO<SceneSelect>(0);
		DeleteGO(this);
	}
	if (Pad(0).IsPress(enButtonStart)) {
		NewGO<Title>(0);
		DeleteGO(this);
	}

	//h_spriteRender->Init(L"sprite/hp.dds", 30, 30);


	//h_spriteRender->SetPosition(h_position);
	

}