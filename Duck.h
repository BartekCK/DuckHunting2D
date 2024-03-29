#pragma once
#include "Node.h"
#include "Path.h"

class Duck:public Node
{
protected:

	ALLEGRO_BITMAP* explosionBitmap = NULL;
	Engine* engine = Engine::getInstance();

	int staticBitmap = 0;
	bool orientationX = true;
	bool orientationY = true;

	int startPositionY;
	static int temp;

	float shiftX = 0;
	float shiftY = 0;
	int moveSpeed = 10;

	const int frames;
	const int levels;
	int point = 0;

public:


	Duck(const char* backgroundBitmap, const int frames, const int levels);
	~Duck();
	void show() override;
	virtual void move(ALLEGRO_EVENT events);
	bool checkShoot(float xShot, float yShot);
	int getPoint();
};

