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

	//////////メンバ変数//////////
private:
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;

	CVector3 bubble_position = CVector3::Zero;
	CVector3 p_a_kyori = CVector3::Zero;



	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
};
