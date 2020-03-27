#include "stdafx.h"
#include "Bubble.h"
#include "Player.h"
#include "BubbleCreator.h"
#include "BubbleChange.h"


BubbleChange::BubbleChange()
{
}

BubbleChange::~BubbleChange()
{
}

bool BubbleChange::Start()
{


	direction = rand() % 3;
	if (direction == 0) {
		bubble_movespeed.x = 3.0f;
	}
	else if (direction == 1) {
		bubble_movespeed.x = 1.0f;
	}
	else if (direction == 2) {
		bubble_movespeed.x = 0.5f;
	}

	return true;
}

