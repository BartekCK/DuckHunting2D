#pragma once
#include "Node.h"
#include <ctime>
#include <Windows.h>


class Duck:public Node
{
private:

	enum direction {LEFT,RIGHT};
	bool orientationX = true;
	bool orientationY = true;

	int startPositionY;
	static int temp;

	float shiftX = 0;
	float shiftY = 0;
	int moveSpeed = 10;

	const int frames;
	const int levels;
public:


	Duck(const char* backgroundBitmap, const int frames, const int levels);

	void show() override;
	void move();
	
private:
	void movementX();
	void movementY();
	void playAnimation();

};

