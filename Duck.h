#pragma once
#include "Node.h"


class Duck:public Node
{
private:
	
public:

	int shiftX = 0;
	int shiftY = 0;
	int moveSpeed = 10;
	const int frames;
	const int levels;

	Duck(const char* backgroundBitmap, const int frames, const int levels);
	void show() override;
};

