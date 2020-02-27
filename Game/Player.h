#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();

	void Update() override;

	const CVector3& Getposition() const {
		return m_position;
	}

	void SetPosition(const CVector3& p_pos)
	{
		m_position =  p_pos;
	}



	/////////Singletonパターン///////////////
		//Playerを一体に限定
	static Player* P_GetInstance()
	{
		return m_instance;
	}
private:
	static Player* m_instance;
	/////////////////////////////////////////

	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CCharacterController m_charaCon;
};

