#pragma once
#include "Player.h"
#include "awa.h"

class isi : public IGameObject
{
public:
	isi();
	~isi();

	//////////メンバ関数//////////

	void Update();
	bool Start();

	const CVector3& Getposition() const {
		return p_isi;
	}

	void Setposition(const CVector3& pos) {
		p_isi = pos;
	}

	//////////メンバ変数//////////
private:
	CVector3 p_isi = CVector3::Zero;

	CVector3 p_i_leng = CVector3::Zero;

	prefab::CSkinModelRender* skin_isi = nullptr;
	
	


	int seisei = 0;
	int state = 0;
	int timer = 0;

	//クラスのロード
	Player* m_player = nullptr;
	awa* m_awa = nullptr;
};

