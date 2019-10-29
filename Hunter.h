#pragma once

#include"Crosshair.h"

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

