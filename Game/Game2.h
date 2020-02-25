#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "Camera.h"

class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();

	void Update();

	//////////�����o�֐�//////////

	//�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

	Player* m_player = nullptr;
	Camera* m_camera = nullptr;

};