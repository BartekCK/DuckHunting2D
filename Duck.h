#pragma once
#include "Node.h"


class Duck:public Node
{
private:
	bool orientationX = true;
	bool orientationY = true;
	bool animation = false;

	int shiftX = 0;
	int shiftY = 0;
	int moveSpeed = 10;
	const int frames;
	const int levels;
public:

	

	Duck(const char* backgroundBitmap, const int frames, const int levels);
	void show() override;
	void move(int screen_width, int screen_height);
	

};

