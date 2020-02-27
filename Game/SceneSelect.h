#pragma once
class SceneSelect : public IGameObject
{
public:
	SceneSelect();
	~SceneSelect();

	///////////メンバ関数/////////////

	void Update();

	///////////メンバ変数/////////////

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

