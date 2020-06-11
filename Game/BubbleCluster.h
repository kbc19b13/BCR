#pragma once

#include "Bubble.h"
class Bullet;

//泡の集合体クラス。
class BubbleCluster : public IGameObject
{
public:
	void Update();

	//クラスターのDelete処理
	void OnDestroy() override;

	//泡の生成時に呼ばれる(自分)
	void AddBubble(Bubble* bubble); 

	//クラスターを合成
	void CombineCluster( BubbleCluster* cluster )
	{
		//子どもリストの泡を登録
		for (auto bubble : cluster->m_bubblse) {
			AddBubble(bubble);
		}
		//合成元をクリア。
		cluster->m_bubblse.clear();
	}

	//クラスターの移動速度を取得。
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
	float m_radius = 0.0f;	//半径。

	CVector3 Diff = CVector3::Zero;

	float a = 0.1f;

	Bullet* tama = nullptr;
};

