#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "Bullet.h"
#include "BubbleCluster.h"

Bubble::Bubble()
{
	isi = FindGO<BubbleCreator>("isi");
	
	
	m_player = Player::P_GetInstance();
}

bool Bubble::Start()
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
	//�N���X�^�[�̓Q�[���I�����ɂ܂Ƃ߂č폜���Ă���̂ŁA�f�X�g���N�^�ł͍폜���Ȃ��B
	m_bubbleCluster = NewGO<BubbleCluster>(0, "�o�u���N���X�^�[");
	m_bubbleCluster->AddBubble(this);

	
	////////////////////////////////////////////
	/*�������������������_����
	�@�����I�ȓ����łȂ������I�ȓ����ɂ���*/
	m_moveSpeedAdd.x = Random().GetRandDouble();
	if (Random().GetRandInt() % 2 == 0) {
		m_moveSpeedAdd.x *= -1.0f;
	}
	m_moveSpeedAdd.z = Random().GetRandDouble();

	m_moveSpeedAdd *= 0.05f;
	////////////////////////////////////////////
	

	//�A�̃T�C�Y��������Ƃ��ς���
	float a = (120 + (rand() % 24 + 1)) / 120.0f ;
	CVector3 scale = { a, a, a };
	bubble_skinmodelrender->SetScale(scale);

	return true;
}

Bubble::~Bubble()
{

	DeleteGO(bubble_skinmodelrender);

}

void Bubble::Update()
{
	
	

	oyako();

	//Player��Bubble�̓����蔻��
	awa_Delete();

	

	bubble_skinmodelrender->SetPosition(bubble_position);
}

//awa�̐e�q�֌W
void Bubble::oyako()
{
	//�A���N���X�^�[�̈ړ����x�œ������i�A�͓����Ȃ��j
	bubble_position += m_bubbleCluster->GetMoveSpeed() + m_moveSpeedAdd;
	
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		if (awa == this) {
			return true;
		}
		if (awa->m_bubbleCluster == m_bubbleCluster) {
			//�����N���X�^�[
			return true;
		}
		//�����ŏ���
		CVector3 a_a_kyori = bubble_position - awa->bubble_position;		//awa��awa�̋������v�Z����
		//�����A���������l�ȉ������������
		if (a_a_kyori.Length() <= 10.0) {
			//�N���X�^�[����������B
			auto oldCluster = awa->m_bubbleCluster;
			m_bubbleCluster->CombineCluster(awa->m_bubbleCluster);
			//�Â��̃N���X�^�[���폜�B
			DeleteGO(oldCluster);
		}
		return true;
	});
}

//awa�̍U���ADeleta����
void Bubble::awa_Delete()
{
	CVector3 p_a_kyori = m_player->GetPosition() - bubble_position;
	if (p_a_kyori.Length() <= 10.0f) {
		DeleteGO(m_bubbleCluster);
	}
}

void Bubble::Deth(float time)
{
	while (Crash) {
		
		DethTime -= GameTime().GetFrameDeltaTime();
		if (DethTime < 0.0f) {
			Crash = false;
		}

	}

}

