#pragma once
class isi : public IGameObject
{
public:
	isi();
	~isi();

	void Update();
	bool Start();

	prefab::CSkinModelRender* skin_isi = nullptr;
	CVector3 lep_isi = CVector3::Zero;

	int state = 0;
	int timer = 0;
};

