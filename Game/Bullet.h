#pragma once
class Game1;
class Bubble;



class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();

	const CVector3& GetPosition() const {
		return m_position;
	}

	void SetPosition(const CVector3& p_pos)
	{
		m_position = p_pos;
	}

	void SetMoveSpeed(const CVector3& p_mspeed)
	{
		m_moveSpeed = p_mspeed;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_�[	
	CVector3 m_position = CVector3::Zero;	//���W�B
	CVector3 m_moveSpeed = CVector3::Zero;	//�ړ����x�B
	int m_timer = 0;						//�^�C�}�[�B
	int amo = 0;							//�e��

	CVector3 scale = CVector3::One;

	//�N���X�̃��[�h
	Game1* game1 = nullptr;
	Bubble* awa = nullptr;

};

