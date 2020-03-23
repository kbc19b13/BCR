#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////�����o�֐�//////////

	void Update();

public:
	const CVector3& GetPosition() const {
		return bubble_position;
	}

	void SetPosition(const CVector3& a_pos) {
		bubble_position = a_pos;
	}

	//////////�����o�ϐ�//////////
private:
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;

	CVector3 bubble_position = CVector3::Zero;
	CVector3 p_a_kyori = CVector3::Zero;



	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
};
