#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	
	/////////////メンバ関数///////////////

	void Update();

	/////////////メンバ変数///////////////

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;


};

