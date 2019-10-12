#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Window.h"

class Configuration {
private:
	Window *window;
	
public:
	Configuration(int screenWidth, int screenHeight, int windowPositionX, int windowPositionY, const char* gameTitle);
	~Configuration();

	void showWindow();

};

