#pragma once
#include "Player.h"


class Camera : public IGameObject
{
public:
	Camera();
	~Camera();
	bool Start() override;
	void Update();

	Player* m_player;	//�v���C���[�B
	CVector3 C_position = { 0.0f, 200.0f, 300.0f };
	CVector3 m_toCameraPos;
};

