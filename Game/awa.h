#pragma once
#include "Player.h"
#include "isi.h"

class awa : public IGameObject
{
public:
	awa();
	~awa();

	//////////�����o�֐�//////////

	void Update();

	const CVector3& Getposition() const{
		return p_awa;
	}

	void SetPosition(const CVector3& a_pos) {
		p_awa = a_pos;
	}


	//////////�����o�ϐ�//////////
private:
	prefab::CSkinModelRender* m_awa = nullptr;

	CVector3 p_awa = CVector3::Zero;
	CVector3 p_a_kyori = CVector3::Zero;

	

	//�N���X�̃��[�h
	Player* m_player = nullptr;
	isi* m_isi = nullptr;
};

