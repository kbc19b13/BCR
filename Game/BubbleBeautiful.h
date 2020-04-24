#pragma once
//‘O•ûéŒ¾
class Bubble;
class Game1;

class BubbleBeautiful : public Bubble
{
public:
	BubbleBeautiful();
	~BubbleBeautiful();

	//////////ƒƒ“ƒoŠÖ”//////////
	bool Start();
	void Update();

private:
	
	Game1* game1 = nullptr;

};

