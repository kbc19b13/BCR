#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////�����o�֐�//////////

	void Update();

public:
	//Position�����炤
	const CVector3& GetPosition() const {
		return bubble_position;
	}
	//Position������������
	void SetPosition(const CVector3& a_pos) {
		bubble_position = a_pos;
	}
	//�ǂ𔽎˂�����
	void StopPosition(CVector3& pos, CVector3& m_speed) {
		if (pos.x <= -75.0f) {
			m_speed.x *= -1.0f;
		}
		if (pos.x >= 75.0f) {
			m_speed.x *= -1.0f;
		}
	}
	//�X�e�[�W�O�Ȃ̂ŁA�E��
	void Kill(CVector3& pos) {
		if (pos.z >= 0.0f) {
			DeleteGO(this);
		}
	}
	//�e�q�֌W�̏���
	void oyako();

	//�A��Delete����
	void awa_Delete();

	//////////�����o�ϐ�//////////
protected:
	//�X�L�����f�������_�[
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;
	//���W
	CVector3 bubble_position = CVector3::Zero;
	//�ړ����x
	CVector3 bubble_movespeed = { 0.0f, 0.0f, 0.2f };
	//����
	int direction = 0;


	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;

	//�e�̃|�C���^��ݒ�
	Bubble* parent = nullptr;
	std::vector<Bubble*> children;	//�q���̃��X�g�B�z��
	
									//std::vector�����I�z��N���X
};
