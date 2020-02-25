#include "stdafx.h"
#include "isi.h"

isi::isi()
{}

isi::~isi()
{}

void isi::Update()
{
	timer++;

	if (timer <= 10)
	{
		state = rand() % 3;
		if(state == 0)
		{

			timer = 0;
		}
		if (state == 1)
		{

			timer = 0;
		}
		if (state == 2)
		{

			timer = 0;
		}
	}
}