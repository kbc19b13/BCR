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



private:
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CCharacterController m_charaCon;
};

