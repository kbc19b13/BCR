#pragma once
//前方宣言
class Bubble;
class Game1;

class BubbleBeautiful : public Bubble
{
public:
	BubbleBeautiful();
	~BubbleBeautiful();

	//////////メンバ関数//////////
	bool Start();
	void Update();

private:
	
	Game1* game1 = nullptr;

};

