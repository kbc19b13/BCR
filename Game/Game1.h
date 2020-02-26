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

	void Update();
	bool Start();

	//////////�����o�֐�//////////

	//�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CLevel m_level;							//���x���B
	
	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;
	
	
	

	Player* m_player = nullptr;
	Camera* m_camera = nullptr;

	isi* m_isi = nullptr;
};