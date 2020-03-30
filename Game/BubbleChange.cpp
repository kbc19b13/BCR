#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "BubbleChange.h"
#include "BubbleCluster.h"

BubbleChange::BubbleChange()
{
}

BubbleChange::~BubbleChange()
{
}

bool BubbleChange::Start()
{

	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());
	bubble_skinmodelrender->SetShadowCasterFlag(true);
	//���؂����}�b�v�����[�h�B
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/awa_spec.dds");
	bubble_skinmodelrender->FindMaterial([&](CModelEffect* mat) {
		mat->SetSpecularMap(m_specMap.GetBody());
	});

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

	//�N���X�^�[�̓Q�[���I�����ɂ܂Ƃ߂č폜���Ă���̂ŁA�f�X�g���N�^�ł͍폜���Ȃ��B
	m_bubbleCluster = NewGO<BubbleCluster>(0,"�o�u���N���X�^�[");
	m_bubbleCluster->AddBubble(this);

	return true;
}

