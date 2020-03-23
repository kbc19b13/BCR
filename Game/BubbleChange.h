#pragma once

class Bubble;

class BubbleChange : public Bubble
{
public:
	BubbleChange();
	~BubbleChange();

	void Update();
	bool Start();

private:
	Bubble* awa = nullptr;
};

