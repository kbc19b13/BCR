#pragma once
#include "Player.h"
//前方宣言
class BubbleCreator;
class BubbleCluster;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////メンバ関数//////////
	bool Start();
	void Update();
protected:
	//更新処理の共通処理
	void UpdateCommon();
public:
	//Positionをもらう
	const CVector3& GetPosition() const {
		return bubble_position;
	}
	//Positionを書き換える
	void SetPosition(const CVector3& a_pos) {
		bubble_position = a_pos;
	}
	//死亡リクエスト
	void RequestDead(int timer) {
		//状態を死亡リクエストに変更。
		m_state = State_RequestDead;
		//死ぬまでの時間を設定。
		m_deadTimer = timer;
	}
	bool StateIsRequestDead() const
	{
		return m_state == State_RequestDead;
	}
	//親子関係の処理
	void oyako();

	//泡のDelete処理
	void awa_Delete();


	CVector3 GetMoveSpeed() {
		return bubble_movespeed;
	}

	void BindBubbleCluster(BubbleCluster* cluster)
	{
		m_bubbleCluster = cluster;
	}

	bool Getbubblecluster()
	{
		return m_bubbleCluster;
	}

	bool GetClean() {
		return clean;
	}

	bool Getcrash() {
		return Crash;
	}
	void SetCrash(bool crash) {
		Crash = crash;
	}
	
	
	//////////メンバ変数//////////
protected:
	enum State {
		State_Normal,
		State_RequestDead,
	};
	State m_state = State_Normal;
	int m_deadTimer = 0;	//死亡タイマー
	//スキンモデルレンダー
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;
	//座標
	CVector3 bubble_position = CVector3::Zero;
	//移動速度
	CVector3 bubble_movespeed = { 0.0f, 0.0f, 0.2f };
	
	//移動速度を足し算？
	CVector3 m_moveSpeedAdd = CVector3::Zero;

	CVector3 Deathscale = CVector3::One;

	CShaderResourceView m_specMap;	//すぺきゅらマップ

	//方向
	int direction = 0;

	bool clean = false;

	//float DethTime = 0.0f;

	bool Crash = true;

	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;

	//親のポインタを設定
	BubbleCluster* m_bubbleCluster = nullptr;	//バブルクラスター。
												
												//std::vector＝動的配列クラス
	
};
