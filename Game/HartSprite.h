#pragma once
class Hartsprit : public IGameObject
{
public:
	bool Start();
	void Update();

private:

	//スプライトレンダー
	prefab::CSpriteRender* m_spriteRender[10];//灰色
	prefab::CSpriteRender* h_spriteRender[10];//赤色

	//スプライトレンダーの座標
	CVector3 m_position = { -616.0f,335.0f,0.0f };
	CVector3 h_position = { -616.0f,335.0f,0.0f };
	CVector3 add_position = { 46.0f, 0.0f, 0.0f };
};
