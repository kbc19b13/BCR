#pragma once
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_�[	
	CVector3 m_position = CVector3::Zero;	//���W�B
	CVector3 m_moveSpeed = CVector3::Zero;	//�ړ����x�B
	int m_timer = 0;						//�^�C�}�[�B
};

