#pragma once

//前方宣言
class Player;
class Bubble;
class BubbleChange;

class BubbleCreator : public IGameObject
{
public:
	BubbleCreator();
	~BubbleCreator();

	//////////メンバ関数//////////

	void Update();
	bool Start();

	const CVector3& Getposition() const {
		return bc_position;
	}

	void Setposition(const CVector3& pos) {
		bc_position = pos;
	}

	//////////メンバ変数//////////
private:
	int seisei = 0;
	int state = 0;
	int timer = 0;

	CVector3 bc_position = CVector3::Zero;

	

	prefab::CSkinModelRender* isi_skinmodelrender = nullptr;






	//クラスのロード
	Player* m_player = nullptr;
	Bubble* awa = nullptr;
	BubbleChange* awa2 = nullptr;
};
