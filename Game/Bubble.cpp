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
	
	oyako();

	

	Kill(bubble_position);

	/*
	//�e�ƖA�Ƃ̓����蔻��
	QueryGOs<Bullet>("awa", [&](Bullet* awa)->bool {
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
	*/

	bubble_skinmodelrender->SetPosition(bubble_position);
}

//awa�̐e�q�֌W
void Bubble::oyako()
{

	if (/*�������e��������*/
		parent != nullptr) {
		bubble_position += parent->bubble_movespeed;
	}
	else {
		bubble_position += bubble_movespeed;
		StopPosition(bubble_position, bubble_movespeed);
	}
	QueryGOs<Bubble>("awa", [&](Bubble* awa) {
		{
			if (this != awa					//������awa����������Ȃ�
				&& parent != awa			//�e�ƂԂ������ꍇ�͖���
				&& children.empty()			//empty = �����
				&& (parent == nullptr		//�e�����Ȃ�
					||						//����
					parent != awa->parent)	//�����o����awa�̐e�ƈꏏ����Ȃ�
				) {

				float rate = 0.5f;			//���̌�̑��x�̒����H

	/////////////////////*�e�����邩�ŏ����𕪂���*//////////////////////////

				/*�����Ƃ��e�����Ȃ��Ƃ��̏d�݂͋ϓ��B*/
				if (parent == nullptr		//�e�����Ȃ�
					&& awa->parent == nullptr//�����o����awa���e�����Ȃ�
					) {
					
					rate = 0.5f;//

				}
				/*���������e�����Ȃ��āA��������͐e������B*/
				else if (parent == nullptr) {
					
					rate = (float)(awa->parent->children.size())			//�e�̎q���̐����Q��
							/												//����Z
							((float)awa->parent->children.size() + 2);		//�e�̎q���̐����Q��(+2�H= �T�C�Y�̊g���H)
					
					//return true; //�f�o�b�O�p�X�L�b�v�@�\
				}
				/*����ɐe�����Ȃ��āA�����ɐe������B*/
				else if (awa->parent == nullptr) {
					
					rate = 1.0f / ((float)parent->children.size() + 2);

				}
				/*�����e������B*/
				else {
					//���̐e�̂ق������͂��傫�����ɓ���
					if (parent->children.size() >							//�e�̎q���̐�
						awa->parent->children.size()) {						//��������awa�̐e�̎q���̐�
						
						return true; //�f�o�b�O�p�X�L�b�v�@�\
					}
					rate = (float)awa->parent->children.size()									//��������awa�̐e�̎q���̐�
							/																	//����Z
							(float)(awa->parent->children.size() + parent->children.size());	//��������awa�̐e�̎q���̐�
				}																				//+�e�̎q���̐�
				rate = std::powf(rate, 0.7f);		//std::powf���ݏ�

				/*�A����������Ȃ��A�e�����Ȃ��Ƃ��B*/
				CVector3 a_a_kyori = bubble_position - awa->bubble_position;		//awa��awa�̋������v�Z����
				//�������A���������l�ȉ���������B
				if (a_a_kyori.Length() <= 10.0) {
					Bubble* oldParent = parent;					//���̐e���o���Ă����B
					parent = awa;								//�e����������awa�ɂ���
					while (parent->parent != nullptr) {			//�e�ɐe�����Ȃ�
						parent = parent->parent;
					}
					if (oldParent != nullptr	//�Â��e�����Ȃ�
						&& oldParent != parent	//�V�����e�ƌÂ��e���ʕ�
						) {													
						for (Bubble* child : oldParent->children) {			//Bubble�|�C���^�^�́@child�@��ݒ� : �Â��e�̎q��
							child->parent = parent;							//child�̐e�������ɏ���������
							parent->children.push_back(child);				//�����������e�̔z����X�V�H
						}
						oldParent->children.clear();						//�Â��e�̎q��(�z��)���N���A(�|��)�H
						oldParent->parent = parent;							//�Â��e�Ɏ����ɏ���������
						parent->children.push_back(oldParent);				//�����������e�̔z����X�V�H
					}
					//�e�̎q���Ɏ�����o�^����B
					parent->children.push_back(this);
					//�ړ����x����������B
					parent->bubble_movespeed.Lerp(rate, bubble_movespeed, parent->bubble_movespeed);
					//���̂���ƁA�������ɑ��x������������B
					parent->bubble_movespeed.z += Random().GetRandDouble() * 0.01f;
				}
			}

			return	true;

		}
		return false;
		});

}

//awa��Deleta����
void Bubble::awa_Delete()
{
	/*
	awa����
	�������v�Z
	Player��awa���������������ׂ�
	�@��������awa���e�����ׂ�
	�A��������awa�̐e�𒲂ׂ�
	�B��������awa������

	�@�A
	�e->�q��(�z��)������
	�e������
	

	�@�A�B
	Player��HP�����炷

	�ł�����A��������
	*/

	//awa�̌���
	QueryGOs<Bubble>("awa", [&](Bubble* awa)->bool {
		//�������v�Z����
		CVector3 p_a_kyori = m_player->GetPosition() - awa->GetPosition();
		if (p_a_kyori.Length() <= 10.0f) {
			if (awa->parent != nullptr)
			{

				for (int i = 0; i > awa->parent->children.size(); i++)
				{
					DeleteGO(children[i]);
				}
					
			}
			//else
			//{
			//
			//}
			
			//Player��HP�����炷

			return false;
		}
		return true;
		});


}