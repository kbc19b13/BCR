#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	
	/////////////メンバ関数///////////////

	void Update();

	/////////////メンバ変数///////////////
	const float awaDown = -1.5f;
	const int surplus = 5;
	const int minus = 2;
	const int SpeedUp = 1.5f;
	int t = 0;
	int State = 0;
	float awaMove = 7.0f;
	float size = 0.0f;
	float jump = 0.0f;

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSpriteRender* m_spriteRender2 = nullptr;
	prefab::CSpriteRender* m_spriteRender3 = nullptr;
	prefab::CSpriteRender* m_spriteRender4 = nullptr;
	//座標
	CVector3 m_position = {-160.0f, 140.0f, 0.0f};
	CVector3 a_position = { 580.0f, 350.0f, 0.0f };
	CVector3 s_position = { 300.0f, -220.0f, 0.0f };
	CVector3 taiki_position = { 800.0f, 600.0f, 0.0f };
	CVector3 m_MoveSpeed = {0.0f, awaDown, 0.0f};
	CVector3 NextPosition = CVector3::Zero;
	CVector3 m_moveSpeedAdd = CVector3::Zero;

	CVector3 m_Scale = CVector3::One;
	CVector3 s_Scale = CVector3::One;
};

