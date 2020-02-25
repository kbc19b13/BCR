#pragma once
class isi : public IGameObject
{
public:
	isi();
	~isi();

	void Update();

	int state = 0;
	int timer = 0;
};

