#pragma once
#include "Player.h"
#include "isi.h"

class awa : public IGameObject
{
public:
	awa();
	~awa();

	//////////メンバ関数//////////

	void Update();

	const CVector3& Getposition() const{
		return p_awa;
	}

	void SetPosition(const CVector3& a_pos) {
		p_awa = a_pos;
	}


	//////////メンバ変数//////////
private:
	prefab::CSkinModelRender* m_awa = nullptr;

	CVector3 p_awa = CVector3::Zero;
	CVector3 p_a_kyori = CVector3::Zero;

	

	//クラスのロード
	Player* m_player = nullptr;
	isi* m_isi = nullptr;
};

