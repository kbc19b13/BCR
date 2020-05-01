#pragma once

#include "Bubble.h"

//泡の集合体クラス。
class BubbleCluster : public IGameObject
{
public:
	void OnDestroy() override;

	void AddBubble(Bubble* bubble); 
	//クラスターを合成
	void CombineCluster( BubbleCluster* cluster )
	{
		//TK_LOG("bubble size %d", cluster->m_bubblse.size());
		for (auto bubble : cluster->m_bubblse) {
			AddBubble(bubble);
		}
		//合成元をクリア。
		cluster->m_bubblse.clear();
	}
	//クラスターの移動速度を取得。
	CVector3 GetMoveSpeed() 
	{
		return bcluster_moveSpeed;
	}
	void Update();
	//クラスターを削除。
	void DeleteCluster(Bubble* bubble);
private:
	void UpdatePosition();
	void UpdateRadius();
private:
	std::vector<Bubble*>	m_bubblse;
	CVector3 bcluster_moveSpeed = CVector3::Zero;
	CVector3 bcluster_position = CVector3::Zero;
	float m_radius = 0.0f;	//半径。
};

