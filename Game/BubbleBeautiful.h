#pragma once
#include "Player.h"
//前方宣言
class BubbleCreator;
class Bubble;
class Game1;

class BubbleBeautiful : public Bubble
{
public:
	BubbleBeautiful();
	~BubbleBeautiful();

	//////////メンバ関数//////////
	bool Start();
	

private:
	
	Game1* game1 = nullptr;

};

