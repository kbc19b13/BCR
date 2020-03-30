#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;
class BubbleCluster;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////�����o�֐�//////////
	bool Start();
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
	
	//�e�q�֌W�̏���
	void oyako();

	//�A��Delete����
	void awa_Delete();


	CVector3 GetMoveSpeed() {
		return bubble_movespeed;
	}
	void BindBubbleCluster(BubbleCluster* cluster)
	{
		m_bubbleCluster = cluster;
	}
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
	CShaderResourceView m_specMap;	//���؂����}�b�v
	
	

	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;

	//�e�̃|�C���^��ݒ�
	BubbleCluster* m_bubbleCluster = nullptr;	//�o�u���N���X�^�[�B
									//std::vector�����I�z��N���X
	CVector3 m_moveSpeedAdd = CVector3::Zero;
};
