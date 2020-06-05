#include "stdafx.h"
#include "Game1.h"
#include "Bullet.h"
#include "Bubble.h"
#include "BubbleChange.h"
#include "BubbleCluster.h"

Bullet::Bullet()
{
}
Bullet::~Bullet()
{
	DeleteGO(m_skinModelRender);
}

bool Bullet::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/Bullet.cmo");
	
	scale * 5.0f;
	m_skinModelRender->SetScale(scale);

	
	
	return true;
}

void Bullet::Update()
{
	//�e�ۂ��ړ�������B
	m_position += m_moveSpeed;

		QueryGOs<Bubble>("awa", [&](Bubble* awa)->bool 
		{
			
			//�A�ƒe�̂Q�_�Ԃ̋������v�Z����B
			CVector3 diff = awa->GetPosition() - m_position;
			//���ꂢ�ȖA�Ȃ�
			//if (awa->GetClean() == true) 
			//{
			//	//�A�C�e���̏���
			//	int item = rand() % 2;
			//	if ( item == 0 ){
 		//			game1->Gets_up() + 1;
			//	}
			//	if (item == 0) {
			//		game1->Gethp_up() + 1;
			//	}
			//}
			//������50.0f�ȉ��ɂȂ��������
			if (diff.Length() < 10.0f) 
			{	
				//�e���̌���

				DeleteGO(awa);

				//�N�G���I���B
				return false;
			}
		return true;
		});
		
	
	//�^�C�}�[�����Z����B
	//m_timer++;
	if (m_timer >= 50) {
		//�^�C�}�[��50�ɂȂ�����C���X�^���X���폜����B
		DeleteGO(this);
	}

	//�e��
	if (amo >= 0) {
		//�e��0�ɂȂ�����A
		//�����[�h�̃A�j���[�V�������Ȃ�����
		//�A�j���[�V�����̍Đ����͒e��łĂȂ��悤�ɂ���
		//�e���5�ǉ�����B

		amo += 5;

	}

	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
}
