#include "stdafx.h"
#include "BubbleCluster.h"
#include "Player.h"

void BubbleCluster::OnDestroy()
{
	float add = 0.0f;
	for (auto bubble : m_bubblse) {
		add += 0.9f;
		//泡に死亡リクエストを送る
		Player* m_player = Player::P_GetInstance();
		Diff = m_player->GetPosition() - bubble->GetPosition();
		bubble->RequestDead( Diff.Length() * 0.5f + add);

	}
}

/*
//関数内で完結すると1_Updateの中で処理が終わり連鎖しない！(描画が一回だけ)

//クラスターを削除。
	void DeleteCluster(Bubble* bubble);

void BubbleCluster::DeleteCluster(Bubble* bubble)
{

	Player* m_player = Player::P_GetInstance();
	Diff = m_player->GetPosition() - bubble->GetPosition();

	DethTime = Diff.Length() * 10.0f;

	while (DethTime > 0.0f) {	//()がfalseになるとループを抜ける

		//DethTime -= GameTime().GetFrameDeltaTime();
		DethTime -= a;
	}

}
*/

//泡の生成時に呼ばれる(自分)
void BubbleCluster::AddBubble(Bubble* bubble)
{
	m_bubblse.push_back(bubble);
	if (m_bubblse.size() == 1) {
		//バブル一個なので、速度合成はしない。
		bcluster_moveSpeed = bubble->GetMoveSpeed();
	}
	else {
		//バブルが複数あるので、重み付きで速度を合成する。
		//速度を平均化。
		float originalRate = 1.0f / m_bubblse.size();
		float rate = originalRate;
		//Lerp = 線形補完(なめらかに)
		bcluster_moveSpeed.Lerp(rate, bubble->GetMoveSpeed(), bcluster_moveSpeed);
		//速度を泡の大きさに応じて遅くする。
		bcluster_moveSpeed *= std::powf(originalRate, 0.01f);
		bcluster_moveSpeed.z = max(0.3f, bcluster_moveSpeed.z);	//画面外に落ちてくれなくなると困るので、zの最小値は0.1にする。
	}
	//親の登録
	bubble->BindBubbleCluster(this);

}

//クラスターの座標を更新。
void BubbleCluster::UpdatePosition()
{
	//クラスターの平均座標を計算。
	bcluster_position = CVector3::Zero;
	for (auto bubble : m_bubblse) {
		bcluster_position += bubble->GetPosition();
	}
	bcluster_position /= m_bubblse.size();
}

//クラスターの半径を更新する。
void BubbleCluster::UpdateRadius()
{
	//クラスターの半径を計算する。
	m_radius = 0.0f;
	if (m_bubblse.size() == 1) {
		m_radius = 1.5f;
	}
	else if (m_bubblse.size() > 1) {
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
}

void BubbleCluster::Update()
{
	//クラスターの座標を更新。
	UpdatePosition();
	//クラスターの半径を更新する。
	UpdateRadius();


	//反射させる
	if (bcluster_position.x + m_radius > 95.0f
		|| bcluster_position.x - m_radius < -95.0f
		) {
		//反射。
		bcluster_moveSpeed.x *= -1.0f;
	}
	//画面外に行くと死ぬ
	if (bcluster_position.z - m_radius > 0.0f) {
		DeleteGO(this);
	}

}
