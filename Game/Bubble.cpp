#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "Bullet.h"

Bubble::Bubble()
{
	isi = FindGO<BubbleCreator>("isi");
	bubble_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	bubble_skinmodelrender->Init(L"modelData/awa.cmo");
	bubble_skinmodelrender->SetPosition(isi->Getposition());

	m_player = Player::P_GetInstance();
}
Bubble::~Bubble()
{

	DeleteGO(bubble_skinmodelrender);

}

void Bubble::Update()
{
	
	bubble_position += bubble_movespeed;
	StopPosition(bubble_position, bubble_movespeed);

	QueryGOs<Bubble>("aaw", [&](Bubble* awa) {
		{
			if (this != awa && awa->parent == NULL) {
				//�A����������Ȃ��A�e�����Ȃ��Ƃ��B
				CVector3 a_a_kyori = bubble_position - awa->bubble_position;
				//�������A���������l�ȉ���������B
				if (a_a_kyori.Length() <= 5.0) {
					awa->parent = this;
				}
			}

			return	true;

		}
		return false;
		});


	QueryGOs<Bullet>("aaw", [&](Bullet* awa)->bool {
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = awa->m_position - bubble_position;
		if (diff.Length() < 500.0f) {	//������500�ȉ��ɂȂ�����B
			//prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			//ss->Init("sound/explosion.wav");	//explosion.wav�����[�h�B
			//ss->SetVolume(0.05f);				//���邳���̂ŉ�������������B
			//ss->Play(false);					//�����V���b�g�Đ��B
			DeleteGO(this);						
			//false��Ԃ�����N�G���͏I���B
			return false;
		}
		//true��Ԃ�����N�G���͌p���B
		return true;
		});


	p_a_kyori = m_player->GetPosition() - GetPosition();
	p_a_kyori.Length();
	if (p_a_kyori.Length() <= 10)
	{
		DeleteGO(this);
	}
	Dess(bubble_position);
	bubble_skinmodelrender->SetPosition(bubble_position);
}