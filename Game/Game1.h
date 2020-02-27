#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "isi.h"
#include "Camera.h"

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////�����o�֐�//////////
	void Update();
	bool Start();



	////////////////////////////////////////////////
	//awa�̊m�F�p�ϐ�_��ŏ���
	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;
	///////////////////////////////////////////////



	//////////�����o�ϐ�//////////
private:
	//�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//���x��
	CLevel m_level;							
	//�X�v���C�g�����_�[
	prefab::CSpriteRender* m_spriteRender;
	//�X�v���C�g�����_�[�̍��W
	CVector3 m_position = { -460,320,0 };

	
	//�N���X�����[�h
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	isi* m_isi = nullptr;
};