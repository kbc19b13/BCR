#pragma once
class Player;

class ResultScene : public IGameObject
{
public:
	ResultScene();
	~ResultScene();

	///////////メンバ関数/////////////

	void Update();

	///////////メンバ変数/////////////

private:
	int gekiha = 0;

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;
	//撃破数
	prefab::CFontRender* defeat = nullptr;
	//スコア
	prefab::CFontRender* score = nullptr;
	prefab::CFontRender* select = nullptr;
	CVector2 score_position = { 400.0f, -240.0f };
	CVector2 defeat_position = { -500.0f, -250.0f };

	//サウンド
	prefab::CSoundSource* buku = nullptr;

	Player* m_player = nullptr;
};

