#pragma once
class SceneSelect : public IGameObject
{
public:
	SceneSelect();
	~SceneSelect();

	///////////�����o�֐�/////////////

	void Update();

	///////////�����o�ϐ�/////////////

	//�X�v���C�g�����_�|
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

