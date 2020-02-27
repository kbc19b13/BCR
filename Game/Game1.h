#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "isi.h"
#include "Camera.h"

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////メンバ関数//////////
	void Update();
	bool Start();



	////////////////////////////////////////////////
	//awaの確認用変数_後で消去
	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;
	///////////////////////////////////////////////



	//////////メンバ変数//////////
private:
	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//レベル
	CLevel m_level;							
	//スプライトレンダー
	prefab::CSpriteRender* m_spriteRender;
	//スプライトレンダーの座標
	CVector3 m_position = { -460,320,0 };

	
	//クラスをロード
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	isi* m_isi = nullptr;
};