#pragma once
class HartSprit : public IGameObject
{
public:
	bool Start();
	void Update();

	void Seta(const int atai) {
		a = atai;
	}

	const int Geta() const {
		return a;
	}

private:
	int a = 10;

	//�X�v���C�g�����_�[
	prefab::CSpriteRender* m_spriteRender[10];//�D�F
	prefab::CSpriteRender* h_spriteRender[10];//�ԐF

	//�X�v���C�g�����_�[�̍��W
	CVector3 m_position = { -616.0f,335.0f,0.0f };
	CVector3 h_position = { -616.0f,335.0f,0.0f };
	CVector3 add_position = { 46.0f, 0.0f, 0.0f };
};
