#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"


class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();

	void Update();

	//////////メンバ関数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;


};