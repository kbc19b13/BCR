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

	//////////メンバ関数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	
	Player* m_player = nullptr;

};