#pragma once
#include "Player.h"
//前方宣言
class BubbleCreator;
class BubbleCluster;
class Bullet;

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
	//死亡リクエスト変換
	void RequestDead(float timer) {
		//状態を死亡リクエストに変更。
		m_state = State_RequestDead;
		//死ぬまでの時間を設定。
		m_deadTimer = timer;
	}
	//死亡リクエスト照合
	bool StateIsRequestDead() const
	{
		return m_state == State_RequestDead;
	}
	//親子関係の処理
	void oyako();

	//泡のDelete処理
	void awa_Delete();

	//移動速度をもらう
	CVector3 GetMoveSpeed() {
		return bubble_movespeed;
	}
	//クラスターの登録(親の登録)
	void BindBubbleCluster(BubbleCluster* cluster)
	{
		m_bubbleCluster = cluster;
	}
	//親をもらう
	bool Getbubblecluster()
	{
		return m_bubbleCluster;
	}
	//きれいか判定
	bool GetClean() {
		return clean;
	}
	
	bool GetTimer() {
		return m_deadTimer;
	}
	
	//////////メンバ変数//////////
protected:
	//生or死・ステート構造体
	enum State {
		State_Normal,
		State_RequestDead,
	};
	State m_state = State_Normal; //ステート
	
	//スキンモデルレンダー
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;
	//座標
	CVector3 bubble_position = CVector3::Zero;
	//移動速度
	CVector3 bubble_movespeed = { 0.0f, 0.0f, 0.2f };
	//移動速度を足し算？
	CVector3 m_moveSpeedAdd = CVector3::Zero;
	//死亡時のサイズ
	CVector3 Deathscale = CVector3::One;
	//死亡タイマー
	float m_deadTimer = 3.0f;	

	CShaderResourceView m_specMap;	//すぺきゅらマップ

	//方向
	int direction = 0;
	//きれいな泡との区別
	bool clean = false;


	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;
	Bullet* tama = nullptr;

	//親のポインタを設定
	BubbleCluster* m_bubbleCluster = nullptr;	//バブルクラスター。
												
												//std::vector＝動的配列クラス
	
};
