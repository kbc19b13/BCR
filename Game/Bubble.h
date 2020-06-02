#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;
class BubbleCluster;
class Bullet;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////�����o�֐�//////////
	bool Start();
	void Update();
protected:
	//�X�V�����̋��ʏ���
	void UpdateCommon();
public:
	//Position�����炤
	const CVector3& GetPosition() const {
		return bubble_position;
	}
	//Position������������
	void SetPosition(const CVector3& a_pos) {
		bubble_position = a_pos;
	}
	//���S���N�G�X�g�ϊ�
	void RequestDead(float timer) {
		//��Ԃ����S���N�G�X�g�ɕύX�B
		m_state = State_RequestDead;
		//���ʂ܂ł̎��Ԃ�ݒ�B
		m_deadTimer = timer;
	}
	//���S���N�G�X�g�ƍ�
	bool StateIsRequestDead() const
	{
		return m_state == State_RequestDead;
	}
	//�e�q�֌W�̏���
	void oyako();

	//�A��Delete����
	void awa_Delete();

	//�ړ����x�����炤
	CVector3 GetMoveSpeed() {
		return bubble_movespeed;
	}
	//�N���X�^�[�̓o�^(�e�̓o�^)
	void BindBubbleCluster(BubbleCluster* cluster)
	{
		m_bubbleCluster = cluster;
	}
	//�e�����炤
	bool Getbubblecluster()
	{
		return m_bubbleCluster;
	}
	//���ꂢ������
	bool GetClean() {
		return clean;
	}
	
	bool GetTimer() {
		return m_deadTimer;
	}
	
	//////////�����o�ϐ�//////////
protected:
	//��or���E�X�e�[�g�\����
	enum State {
		State_Normal,
		State_RequestDead,
	};
	State m_state = State_Normal; //�X�e�[�g
	
	//�X�L�����f�������_�[
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;
	//���W
	CVector3 bubble_position = CVector3::Zero;
	//�ړ����x
	CVector3 bubble_movespeed = { 0.0f, 0.0f, 0.2f };
	//�ړ����x�𑫂��Z�H
	CVector3 m_moveSpeedAdd = CVector3::Zero;
	//���S���̃T�C�Y
	CVector3 Deathscale = CVector3::One;
	//���S�^�C�}�[
	float m_deadTimer = 3.0f;	

	CShaderResourceView m_specMap;	//���؂����}�b�v

	//����
	int direction = 0;
	//���ꂢ�ȖA�Ƃ̋��
	bool clean = false;


	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
	Bullet* tama = nullptr;

	//�e�̃|�C���^��ݒ�
	BubbleCluster* m_bubbleCluster = nullptr;	//�o�u���N���X�^�[�B
												
												//std::vector�����I�z��N���X
	
};
