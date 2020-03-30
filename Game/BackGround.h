#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	bool Start();
	void Update();

	const CVector3& Getposition() const {
		return bg_position;
	}

	void Setposition(const CVector3& pos) {
		bg_position = pos;
	}

private:
	prefab::CSkinModelRender* bg_skinModelRender = nullptr;
	CVector3 bg_position = CVector3::Zero;
	CShaderResourceView m_specMap;	//すぺきゅらマップ。
};

