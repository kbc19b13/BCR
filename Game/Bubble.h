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
	

public:
	//Positionをもらう
	const CVector3& GetPosition() const {
		return bubble_position;
	}
	//Positionを書き換える
	void SetPosition(const CVector3& a_pos) {
		bubble_position = a_pos;
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


	bool Getcrash() {
		return Crash;
	}
	void SetCrash(bool crash) {
		Crash = crash;
	}
	void SetDethTime(const float time) {
		DethTime = time;
	}
	float GetDethTime() {
		return DethTime;
	}
	void Deth(float time);

	//////////メンバ変数//////////
protected:
	//スキンモデルレンダー
	prefab::CSkinModelRender* bubble_skinmodelrender = nullptr;
	//座標
	CVector3 bubble_position = CVector3::Zero;
	//移動速度
	CVector3 bubble_movespeed = { 0.0f, 0.0f, 0.2f };
	//方向
	int direction = 0;
	//???
	CVector3 m_moveSpeedAdd = CVector3::Zero;

	CShaderResourceView m_specMap;	//すぺきゅらマップ
	

	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;

	//親のポインタを設定
	BubbleCluster* m_bubbleCluster = nullptr;	//バブルクラスター。
												
												//std::vector＝動的配列クラス
	float DethTime = 0.0f;
	bool Crash = true;
};
