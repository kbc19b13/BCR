#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;
class Bubble;

class BubbleChange : public Bubble
{
public:
	BubbleChange();
	~BubbleChange();

	//////////�����o�֐�//////////

	void Update();
	bool Start();

	const CVector3& GetPosition() const {
		return bubble2_position;
	}

	void SetPosition(const CVector3& a_pos) {
		bubble2_position = a_pos;
	}

private:
	prefab::CSkinModelRender* bubble2_skinmodelrender = nullptr;

	CVector3 bubble2_position = CVector3::Zero;
	CVector3 bubble2_movespeed = {1.0f, 0.0f, 1.0f};

	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
	Bubble* awa = nullptr;
};

