#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	
	/////////////�����o�֐�///////////////

	void Update();

	/////////////�����o�ϐ�///////////////

	//�X�v���C�g�����_�|
	prefab::CSpriteRender* m_spriteRender = nullptr;


};

