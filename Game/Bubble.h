#pragma once
#include "Player.h"
//前方宣言
class BubbleCreator;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////メンバ関数//////////

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
	//////////メンバ変数//////////
private:
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;

	CVector3 bubble_position = CVector3::Zero;
	CVector3 bubble_movespeed = { 1.0f, 0.0f, 1.0f };
	CVector3 p_a_kyori = CVector3::Zero;



	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
};
