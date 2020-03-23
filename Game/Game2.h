#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
//前方宣言
class Camera;

class Game2 : public IGameObject
{
public:
	Game2();
	~Game2();

	//////////メンバ関数//////////

	void Update();
	bool Start();

	/////////Singletonパターン///////////////
		//Game2を一体に限定
	static Game2* P_GetInstance()
	{
		return m_instance;
	}
private:
	static Game2* m_instance;
	/////////////////////////////////////////

	//////////メンバ変数//////////

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;

	prefab::CSpriteRender* m_spriteRender;
	prefab::CSpriteRender* h_spriteRender;

	CVector3 m_position = { -460,320,0 };		//座標。
	CVector3 h_position = { -460,320,0 };

	Player* m_player = nullptr;
	Camera* m_camera = nullptr;

};