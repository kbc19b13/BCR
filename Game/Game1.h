#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();

	void Update();

	//////////�����o�֐�//////////

	//�X�L�����f�������_�[
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	
	Player* m_player = nullptr;

};