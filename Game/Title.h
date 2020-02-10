#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	
	void Update();

	/////////////メンバ関数///////////////

	//スプライトレンダ－
	prefab::CSpriteRender* m_spriteRender = nullptr;


};

