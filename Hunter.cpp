#include "Hunter.h"

int Hunter::points = 0;


Hunter::Hunter(ALLEGRO_DISPLAY* display)
{
	cross = new Crosshair(display);
}


Hunter::~Hunter()
{
	delete cross;
}

void Hunter::addPoints(int points)
{
	this->points += points;
}

int Hunter::getPoints()
{
	return this->points;
}

Crosshair* Hunter::getCross()
{
	return this->cross;
}

