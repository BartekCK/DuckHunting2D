#pragma once
#include "Node.h"
#include "Path.h"
#include <ctime>
#include <Windows.h>
#include <stdlib.h>

class Duck:public Node
{
private:

	
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

	static int const point = 100;

	Duck(const char* backgroundBitmap, const int frames, const int levels);

	void show() override;
	void move();
	bool checkShoot(float xShot, float yShot,int i);
};

