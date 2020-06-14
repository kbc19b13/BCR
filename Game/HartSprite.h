#pragma once
class Game1;

class HartSprit : public IGameObject
{
public:
	HartSprit();
	~HartSprit();

	bool Start();
	void Update();

	

private:
	int State = 0;
	int b = 0;
	int c = 0;
	int old = 0;

	//スプライトレンダー
	prefab::CSpriteRender* m_spriteRender[10] = { nullptr };//灰色
	prefab::CSpriteRender* h_spriteRender[11] = { nullptr };//赤色

	//スプライトレンダーの座標
	CVector3 m_position = { -616.0f,335.0f,0.0f };
	CVector3 h_position = { -662.0f,335.0f,0.0f };
	CVector3 add_position = { 46.0f, 0.0f, 0.0f };

	Game1* game1 = nullptr;
};
