#pragma once
class awa : public IGameObject
{
public:
	awa();
	~awa();

	void Update();

	prefab::CSkinModelRender* m_awa = nullptr;

	CVector3 p_awa = CVector3::Zero;
};

