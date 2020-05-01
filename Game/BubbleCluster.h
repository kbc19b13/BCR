#pragma once

#include "Bubble.h"

//�A�̏W���̃N���X�B
class BubbleCluster : public IGameObject
{
public:
	void OnDestroy() override;

	void AddBubble(Bubble* bubble); 
	//�N���X�^�[������
	void CombineCluster( BubbleCluster* cluster )
	{
		//TK_LOG("bubble size %d", cluster->m_bubblse.size());
		for (auto bubble : cluster->m_bubblse) {
			AddBubble(bubble);
		}
		//���������N���A�B
		cluster->m_bubblse.clear();
	}
	//�N���X�^�[�̈ړ����x���擾�B
	CVector3 GetMoveSpeed() 
	{
		return bcluster_moveSpeed;
	}
	void Update();
	//�N���X�^�[���폜�B
	void DeleteCluster(Bubble* bubble);
private:
	void UpdatePosition();
	void UpdateRadius();
private:
	std::vector<Bubble*>	m_bubblse;
	CVector3 bcluster_moveSpeed = CVector3::Zero;
	CVector3 bcluster_position = CVector3::Zero;
	float m_radius = 0.0f;	//���a�B
};

