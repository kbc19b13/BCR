#pragma once

#include "Bubble.h"
class Bullet;

//�A�̏W���̃N���X�B
class BubbleCluster : public IGameObject
{
public:
	void Update();

	//�N���X�^�[��Delete����
	void OnDestroy() override;

	//�A�̐������ɌĂ΂��(����)
	void AddBubble(Bubble* bubble); 

	//�N���X�^�[������
	void CombineCluster( BubbleCluster* cluster )
	{
		//�q�ǂ����X�g�̖A��o�^
		for (auto bubble : cluster->m_bubblse) {
			AddBubble(bubble);
		}
		//���������N���A�B
		cluster->m_bubblse.clear();
	}

	//�N���X�^�[�̈ړ����x���擾�B
	CVector3& GetMoveSpeed() 
	{
		return bcluster_moveSpeed;
	}

private:
	void UpdatePosition();
	void UpdateRadius();
private:
	std::vector<Bubble*>	m_bubblse;
	CVector3 bcluster_moveSpeed = CVector3::Zero;
	CVector3 bcluster_position = CVector3::Zero;
	float m_radius = 0.0f;	//���a�B

	CVector3 Diff = CVector3::Zero;

	float a = 0.1f;

	Bullet* tama = nullptr;
};

