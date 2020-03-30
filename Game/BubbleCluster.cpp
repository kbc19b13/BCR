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
		bcluster_moveSpeed = bubble->GetMoveSpeed();
	}else{
		//バブルが複数あるので、重み付きで速度を合成する。
		//速度を平均化。
		float originalRate = 1.0f / m_bubblse.size();
		float rate = originalRate;
		bcluster_moveSpeed.Lerp( rate, bubble->GetMoveSpeed(), bcluster_moveSpeed ) ;
		//速度を泡の大きさに応じて遅くする。
		bcluster_moveSpeed *= std::powf(originalRate, 0.01f);
		bcluster_moveSpeed.z = max(0.3f, bcluster_moveSpeed.z);	//画面外に落ちてくれなくなると困るので、zの最小値は0.1にする。
	}
	bubble->BindBubbleCluster(this);
	
	
}
void BubbleCluster::UpdatePosition()
{
	//クラスターの平均座標を計算。
	bcluster_position = CVector3::Zero;
	for (auto bubble : m_bubblse) {
		bcluster_position += bubble->GetPosition();
	}
	bcluster_position /= m_bubblse.size();
}
void BubbleCluster::UpdateRadius()
{
	//クラスターの半径を計算する。
	m_radius = 0.0f;
	for (auto bubble : m_bubblse) {
		auto pos = bubble->GetPosition();
		//クラスターの中心座標から、バブルまでの距離を計算。
		auto dist = pos - bcluster_position;
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
	//クラスターの半径を更新する。
	UpdateRadius();
	//反射させる
	if (bcluster_position.x + m_radius > 75.0f			
		|| bcluster_position.x - m_radius < -75.0f
		) {
		//反射。
		bcluster_moveSpeed.x *= -1.0f;
	}
	//画面外に行くと死ぬ
	if (bcluster_position.z - m_radius > 0.0f) {
		DeleteGO(this);
	}

}
void BubbleCluster::DeleteCluster() 
{
	/*
	クラスターの理解を深める
	Delete処理の実装
	｛
	（半径を使用してif文を作成）
	クラスター全体消去から個体消去に変換
	子供のリストから一個ずつ消していく
	最後に親を消す
	クラスターと一緒に泡も消える
	｝
	↑で連鎖させる？

	*/



}