#pragma once
#include "Player.h"

class isi : public IGameObject
{
public:
	isi();
	~isi();

	void Update();
	bool Start();

	prefab::CSkinModelRender* skin_isi = nullptr;
	CVector3 lep_isi = CVector3::Zero;

	prefab::CSkinModelRender* skin_awa = nullptr;
	CVector3 p_i_leng = CVector3::Zero;

	int seisei = 0;
	int state = 0;
	int timer = 0;

private:
	Player* m_player;
	
};

