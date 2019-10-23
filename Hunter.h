#pragma once

#include"Crosshair.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Hunter
{
	Crosshair* cross = NULL;

public:
	static int points;
	Hunter(ALLEGRO_DISPLAY* display);
	~Hunter();
	void addPoints(int points);
	int getPoints();
	Crosshair* getCross();
};

