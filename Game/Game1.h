#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "isi.h"

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();

	void Update();
	bool Start();

	//////////メンバ関数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CLevel m_level;							//レベル。

	
	


	Player* m_player = nullptr;
	isi* m_isi = nullptr;
};