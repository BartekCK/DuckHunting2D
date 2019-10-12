#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Window.h"

class Configuration {
private:
	Window *window = NULL;
	
public:
	Configuration();
	~Configuration();


	void windowConfigure(int screenWidth, int screenHeight, const char* gameTitle, const char* backgroundBitmap);
	void showScene();
};

