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
	///////////���؂����}�b�v.�C�ɂ��Ȃ�/////////////////////////////

	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());
	bubble_skinmodelrender->SetShadowCasterFlag(true);
	//���؂����}�b�v�����[�h�B
	m_specMap.CreateFromDDSTextureFromFile(L"modelData/awa_spec.dds");
	bubble_skinmodelrender->FindMaterial([&](CModelEffect* mat) {
		mat->SetSpecularMap(m_specMap.GetBody());
	});

	/////////////////////////////////////////////////////////////////////

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

//�X�V�����̋��ʏ���
void Bubble::UpdateCommon()
{
	switch (m_state)
	{
		//�ʏ폈��
	case State_Normal:

		oyako();
		//Player��Bubble�̓����蔻��
		awa_Delete();

		QueryGOs<Bullet>("tama", [&](Bullet* tama)
		{

			//�A�ƒe�̂Q�_�Ԃ̋������v�Z����B
			CVector3 diff = bubble_position - tama->GetPosition();

			//���ꂢ�ȖA�Ȃ�
			//if (awa->GetClean() == true) 
			//{
			//	//�A�C�e���̏���
			//	int item = rand() % 2;
			//	if ( item == 0 ){
			//		game1->Gets_up() + 1;
			//	}
			//	if (item == 0) {
			//		game1->Gethp_up() + 1;
			//	}
			//}

			//������50.0f�ȉ��ɂȂ��������
			if (diff.Length() < 10.0f)
			{
				//�e���̌���
				DeleteGO(m_bubbleCluster);

				//�N�G���I���B
				return false;
			}
			return true;
		});

		bubble_skinmodelrender->SetPosition(bubble_position);
		break;

		//���S���N�G�X�g�����Ă���Ƃ��̏���
	case State_RequestDead:
		
		m_deadTimer -= 0.05f;
		Deathscale += Deathscale * 0.005;
		if (Deathscale.x <  1.35f && Deathscale.y < 1.35f && Deathscale.z < 1.35f ) {
			//�X�P�[����傫������
			bubble_skinmodelrender->SetScale(Deathscale);
		}
		
		if (m_deadTimer < 0.0f ) {
			//�^�C�}�[��0�ȉ��ɂȂ����̂Ŏ��S�B

			//�G�t�F�N�g�Đ�
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/test2.efk");
			effect->SetPosition(bubble_position);

			DeleteGO(this);
		}
		

		break;
	}
}

void Bubble::Update()
{
	UpdateCommon();	
}

//awa�̐e�q�֌W
void Bubble::oyako()
{
	//�A���N���X�^�[�̈ړ����x�œ������i�A�͓����Ȃ��j
	bubble_position += m_bubbleCluster->GetMoveSpeed() + m_moveSpeedAdd;
	
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		////////////////////////////////////////////////////////////////////
		if (awa == this || awa->StateIsRequestDead()) {		//���S���Ă���
			return true;
		}
		if (awa->m_bubbleCluster == m_bubbleCluster) {		//�����N���X�^�[
			return true;
		}
		///////////////////////////////////////////////////////////////////

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
		//Player�̗̑͌����I�I

		DeleteGO(m_bubbleCluster);
	}
}


