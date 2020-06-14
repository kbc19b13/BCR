#pragma once
class Player;

class ResultScene : public IGameObject
{
public:
	ResultScene();
	~ResultScene();

	///////////�����o�֐�/////////////

	void Update();

	///////////�����o�ϐ�/////////////

private:
	int gekiha = 0;

	//�X�v���C�g�����_�|
	prefab::CSpriteRender* m_spriteRender = nullptr;
	//���j��
	prefab::CFontRender* defeat = nullptr;
	//�X�R�A
	prefab::CFontRender* score = nullptr;
	prefab::CFontRender* select = nullptr;
	CVector2 score_position = { 400.0f, -240.0f };
	CVector2 defeat_position = { -500.0f, -250.0f };

	//�T�E���h
	prefab::CSoundSource* buku = nullptr;

	Player* m_player = nullptr;
};

