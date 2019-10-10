#pragma once


#include <iostream>
#include <allegro5/allegro.h>

class Configuration {

private:
	ALLEGRO_DISPLAY* display = NULL;
public:
	Configuration();
	~Configuration();

	void showDisplay();
};

