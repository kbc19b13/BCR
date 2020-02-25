#pragma once
#include "Player.h"

class awa : public IGameObject
{
public:
	awa();
	~awa();

	void Update();

	prefab::CSkinModelRender* m_awa = nullptr;

	CVector3 p_awa = CVector3::Zero;

	CVector3 p_a_kyori = CVector3::Zero;

	Player* m_player = nullptr;
};

