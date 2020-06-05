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
	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダー	
	CVector3 m_position = CVector3::Zero;	//座標。
	CVector3 m_moveSpeed = CVector3::Zero;	//移動速度。
	int m_timer = 0;						//タイマー。
	int amo = 0;							//弾薬

	CVector3 scale = CVector3::One;

	//クラスのロード
	Game1* game1 = nullptr;
	Bubble* awa = nullptr;

};

