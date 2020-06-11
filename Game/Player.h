#pragma once
class Bubble;
class Game1;
//class Game2;

class Player : public IGameObject
{
public:
	Player();
	~Player();

	void Update() override;
	bool Start();
	//void AnimationControl();

	void Player_Move();

	CVector3 Bullet_Direction();

	const CVector3& GetPosition() const {
		return m_position;
	}

	void SetPosition(const CVector3& p_pos)
	{
		m_position =  p_pos;
	}

	int m_timer = 0;
	int amo = 0;

	/////////Singleton�p�^�[��///////////////
		//Player����̂Ɍ���
	static Player* P_GetInstance()
	{
		return m_instance;
	}
private:
	static Player* m_instance;
	/////////////////////////////////////////


	enum EnAnimationClip {
		enAnimationClip_walk,	//�����A�j���[�V�����B
		enAnimationClip_num,	//�A�j���[�V�����N���b�v�̐��B
	};

	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CVector3 d_moveSpeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;

	//�N���X�̃��[�h
	Bubble* awa = nullptr;
	Game1* game1 = nullptr;
	CAnimationClip m_animClips[enAnimationClip_num];
};

