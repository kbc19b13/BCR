#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"

//前方宣言
class BubbleCreator;
class Camera;
class BackGround;
class Hartsprit;

class Game1 : public IGameObject
{
public:
	Game1();
	~Game1();


	//////////メンバ関数//////////
	void Update();
	bool Start();

	void OnDestroy()override;
	/*
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
	/*void CapaUp();
	void Recovery();
	void Protection();

	void Seta(const int atai) {
		a = atai;
	}

	int Geta(){
		return a;
	}

	int Getitem_State()
	{
		return item_State;
	}
	
	void Setitem_State(int state)
	{
		item_State = state;
	}
	*/

	

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
	//int a = 10;
	/*int Item_State = 0;
	int item_State = 0;*/

	

	//スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSkinModelRender* mo = nullptr;
	//レベル
	CLevel m_level;
	
	//サウンド
	prefab::CSoundSource* BGM = nullptr;
	prefab::CSoundSource* BGM2 = nullptr;

	//フォント
	/*prefab::CFontRender* Capa = nullptr;
	prefab::CFontRender* Reco = nullptr;
	prefab::CFontRender* Prot = nullptr;*/

	//スプライトレンダーの座標
	CVector3 s_up_position = { 0.0f,0.0f,0.0f };
	CVector3 hp_up_position = { 0.0f,0.0f,0.0f };
	//アイテム個数
	/*int s_up = 0;
	int hp_up = 0;*/

	//std::vector<Sprite*> s_up_spriteRender;

	//クラスをロード
	Player* m_player = nullptr;
	Camera* m_camera = nullptr;
	BubbleCreator* isi = nullptr;
	Hartsprit* m_hsp = nullptr;
	prefab::CDirectionLight* m_dirLig = nullptr;
};