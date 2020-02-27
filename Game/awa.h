#pragma once
#include "Player.h"

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

	void SetPosition(const CVector3& pos) {
		p_awa = pos;
	}


	//////////メンバ変数//////////
private:

	CVector3 p_awa = CVector3::Zero;
	CVector3 p_a_kyori = CVector3::Zero;

	prefab::CSkinModelRender* m_awa = nullptr;

	//クラスのロード
	Player* m_player = nullptr;
};

