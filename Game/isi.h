#pragma once
#include "Player.h"

class isi : public IGameObject
{
public:
	isi();
	~isi();

	//////////�����o�֐�//////////

	void Update();
	bool Start();

	void Setposition(const CVector3& pos) {
		p_isi = pos;
	}

	//////////�����o�ϐ�//////////
private:
	CVector3 p_isi = CVector3::Zero;

	CVector3 p_i_leng = CVector3::Zero;

	prefab::CSkinModelRender* skin_isi = nullptr;
	prefab::CSkinModelRender* skin_awa = nullptr;
	


	int seisei = 0;
	int state = 0;
	int timer = 0;

	//�N���X�̃��[�h
	Player* m_player;
	
};

