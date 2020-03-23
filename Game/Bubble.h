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

	void StopPosition(CVector3& pos, CVector3& m_speed) {
		if (pos.x <= -75.0f) {
			m_speed.x = m_speed.x * -1.0f;
		}
		if (pos.x >= 75.0f) {
			m_speed.x = m_speed.x * -1.0f;
		}
	}
	//////////�����o�ϐ�//////////
private:
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;

	CVector3 bubble_position = CVector3::Zero;
	CVector3 bubble_movespeed = { 1.0f, 0.0f, 1.0f };
	CVector3 p_a_kyori = CVector3::Zero;



	//�N���X�̃��[�h
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
};
