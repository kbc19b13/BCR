#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();

	void Update() override;

	/*void SetPosition(CVector3 p_pos)
	{
		m_position =  p_pos;
	}*/

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;	//âÒì]ÅB
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_charaCon;
};

