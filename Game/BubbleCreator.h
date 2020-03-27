#pragma once

//�O���錾
class Player;
class Bubble;
class BubbleChange;

class BubbleCreator : public IGameObject
{
public:
	BubbleCreator();
	~BubbleCreator();

	//////////�����o�֐�//////////

	void Update();
	bool Start();

	const CVector3& Getposition() const {
		return bc_position;
	}

	void Setposition(const CVector3& pos) {
		bc_position = pos;
	}

	//////////�����o�ϐ�//////////
private:
	int seisei = 0;
	int state = 0;
	int timer = 0;

	CVector3 bc_position = CVector3::Zero;

	

	prefab::CSkinModelRender* isi_skinmodelrender = nullptr;






	//�N���X�̃��[�h
	Player* m_player = nullptr;
	Bubble* awa = nullptr;
	BubbleChange* awa2 = nullptr;
};
