#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();

	void Update() override;

	const CVector3& GetPosition() const {
		return m_position;
	}

	void SetPosition(const CVector3& p_pos)
	{
		m_position =  p_pos;
	}



	/////////Singletonƒpƒ^[ƒ“///////////////
		//Player‚ğˆê‘Ì‚ÉŒÀ’è
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

