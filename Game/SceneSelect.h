#pragma once
class SceneSelect : public IGameObject
{
	SceneSelect();
	~SceneSelect();

	void Update();

	///////////�����o�֐�/////////////

	//�X�v���C�g�����_�|
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

