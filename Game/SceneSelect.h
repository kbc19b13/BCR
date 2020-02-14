#pragma once
class SceneSelect : public IGameObject
{
public:
	SceneSelect();
	~SceneSelect();

	void Update();

	///////////メンバ関数/////////////

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

