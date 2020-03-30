#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
//前方宣言
class BubbleCreator;
class Camera;

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////メンバ関数//////////
	void Update();
	bool Start();
	
	const CVector3& GetScale() const {
		
		return scale;
	}
	void SetScale(const CVector3& a_pos) {
		scale = a_pos;
	}

	////////////////////////////////////////////////
	//awaの確認用変数_後で消去
	prefab::CSkinModelRender* m_skin = nullptr;
	CVector3 pos = CVector3::Zero;
	///////////////////////////////////////////////
	float s = 15.0f;


	
	/////////Singletonパターン///////////////
		//Game1を一体に限定
	static Game1* P_GetInstance()
	{
		return m_instance;
	}
private:
	static Game1* m_instance;
	/////////////////////////////////////////

	//////////メンバ変数//////////
	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	//レベル
	CLevel m_level;							
	//スプライトレンダー
	prefab::CSpriteRender* m_spriteRender;//hpバー
	prefab::CSpriteRender* h_spriteRender;//hp
	//スプライトレンダーの座標
	CVector3 m_position = { -460,320,0 };
	CVector3 h_position = { -460,320,0 };

	CVector3 scale = {s, 1.0f, 1.0f};
	

	//クラスをロード
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	BubbleCreator* isi = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};