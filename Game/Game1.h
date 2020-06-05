#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"

//前方宣言
class BubbleCreator;
class Camera;
class BackGround;

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

	int Gets_up() {
		return s_up;
	}
	int Gethp_up() {
		return hp_up;
	}

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

	CVector3 scale = { s, 1.0f, 1.0f };

	float s = 15.0f;

	//アイテムの個数表示
	//スプライトレンダー
	prefab::CSpriteRender* s_up_spriteRender[10] = { nullptr };
	prefab::CSpriteRender* hp_up_spriteRender[10] = { nullptr };
	//スプライトレンダーの座標
	CVector3 s_up_position = { 0.0f,0.0f,0.0f };
	CVector3 hp_up_position = { 0.0f,0.0f,0.0f };
	//アイテム個数
	int s_up = 0;
	int hp_up = 0;

	//std::vector<Sprite*> s_up_spriteRender;

	//クラスをロード
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	BubbleCreator* isi = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};