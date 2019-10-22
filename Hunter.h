#pragma once

#include"Crosshair.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Hunter
{
	static int points;
	Crosshair* cross = NULL;

public:

	Hunter(ALLEGRO_DISPLAY* display);
	~Hunter();
	void addPoints(int points);
	int getPoints();
	Crosshair* getCross();
};

