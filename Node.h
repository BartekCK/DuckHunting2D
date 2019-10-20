#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Scene.h"

using namespace std;


class Node
{
protected:

	ALLEGRO_BITMAP* objectBitmap = NULL;

	int xPosition = 0;
	int yPosition = 0;

	int width = 0;
	int height = 0;
	const char* backgroundBitmap;

public:
	Node(const char* backgroundBitmap);
	~Node();

	int getWidth();
	int getHeight();

	void setXposition(int x);
	void setYposition(int y);
	int getXposition();
	int getYposition();
	virtual void show() = 0;
};

