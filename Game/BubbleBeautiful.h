#pragma once
#include "Player.h"
//�O���錾
class BubbleCreator;
class Bubble;
class Game1;

class BubbleBeautiful : public Bubble
{
public:
	BubbleBeautiful();
	~BubbleBeautiful();

	//////////�����o�֐�//////////
	bool Start();
	

private:
	
	Game1* game1 = nullptr;

};

