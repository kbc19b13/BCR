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

	//////////メンバ関数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;

	Player* m_player = nullptr;
	Camera* m_camera = nullptr;

};