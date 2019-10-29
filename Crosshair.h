#pragma once
#include <iostream>
#include "Path.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Crosshair
{
private:
	ALLEGRO_BITMAP* objectBitmap = NULL;
	ALLEGRO_DISPLAY* display = NULL;

	int bitmapWidth = 0;
	int bitmapHeight = 0;

public:
	Crosshair(ALLEGRO_DISPLAY* display);
	~Crosshair();
	void showCross(float x, float y);

};

