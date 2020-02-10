#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"


class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();

	void Update();

	//////////メンバ関数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	

};