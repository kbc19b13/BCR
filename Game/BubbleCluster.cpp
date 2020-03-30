#include "stdafx.h"
#include "BubbleCluster.h"

void BubbleCluster::OnDestroy()
{
	for (auto bubble : m_bubblse) {
		DeleteGO(bubble);
	}
}
void BubbleCluster::AddBubble(Bubble* bubble)
{
	m_bubblse.push_back(bubble);
	if (m_bubblse.size() == 1) {
		//バブル一個なので、速度合成はしない。
		m_moveSpeed = bubble->GetMoveSpeed();
	}else{
		//バブルが複数あるので、重み付きで速度を合成する。
		//速度を平均化。
		float originalRate = 1.0f / m_bubblse.size();
		float rate = originalRate;
		m_moveSpeed.Lerp( rate, bubble->GetMoveSpeed(), m_moveSpeed ) ;
		//速度を泡の大きさに応じて遅くする。
		m_moveSpeed *= std::powf(originalRate, 0.01f);
		m_moveSpeed.z = max(0.3f, m_moveSpeed.z);	//画面外に落ちてくれなくなると困るので、zの最小値は0.1にする。
	}
	bubble->BindBubbleCluster(this);
	//クラスターの半径を計算する。
	
}
void BubbleCluster::UpdatePosition()
{
	//クラスターの平均座標を計算。
	m_position = CVector3::Zero;
	for (auto bubble : m_bubblse) {
		m_position += bubble->GetPosition();
	}
	m_position /= m_bubblse.size();
}
void BubbleCluster::UpdateRadius()
{
	m_radius = 0.0f;
	for (auto bubble : m_bubblse) {
		auto pos = bubble->GetPosition();
		//クラスターの中心座標から、バブルまでの距離を計算。
		auto dist = pos - m_position;
		float length = dist.Length();
		//半径を更新。
		if (m_radius < length) {
			//こっちのほうが大きいので、更新する。
			m_radius = length;
		}
	}
}
void BubbleCluster::Update()
{
	//クラスターの座標を更新。
	UpdatePosition();
	//半径を更新する。
	UpdateRadius();
	if (m_position.x + m_radius > 75.0f
		|| m_position.x - m_radius < -75.0f
		) {
		//反射。
		m_moveSpeed.x *= -1.0f;
	}

	if (m_position.z - m_radius > 0.0f) {
		DeleteGO(this);
	}

}