#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	
	void Update();

	/////////////�����o�֐�///////////////

	//�X�v���C�g�����_�|
	prefab::CSpriteRender* m_spriteRender = nullptr;


};

