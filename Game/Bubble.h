#pragma once
#include "Player.h"
//前方宣言
class BubbleCreator;

class Bubble : public IGameObject
{
public:
	Bubble();
	~Bubble();

	//////////メンバ関数//////////

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
	//壁を反射させる
	void StopPosition(CVector3& pos, CVector3& m_speed) {
		if (pos.x <= -75.0f) {
			m_speed.x *= -1.0f;
		}
		if (pos.x >= 75.0f) {
			m_speed.x *= -1.0f;
		}
	}
	//ステージ外なので、殺す
	void Kill(CVector3& pos) {
		if (pos.z >= 0.0f) {
			DeleteGO(this);
		}
	}
	//親子関係の処理
	void oyako();

	//泡のDelete処理
	void awa_Delete();

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


	//クラスのロード
	Player* m_player = nullptr;
	BubbleCreator* isi = nullptr;

	//親のポインタを設定
	Bubble* parent = nullptr;
	std::vector<Bubble*> children;	//子供のリスト。配列
	
									//std::vector＝動的配列クラス
};
