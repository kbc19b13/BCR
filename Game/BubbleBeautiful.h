#pragma once
//�O���錾
class Bubble;
class Game1;

class BubbleBeautiful : public Bubble
{
public:
	BubbleBeautiful();
	~BubbleBeautiful();

	//////////�����o�֐�//////////
	bool Start();
	void Update();

private:
	
	Game1* game1 = nullptr;

};

