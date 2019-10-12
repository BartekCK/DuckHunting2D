#pragma once

#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>

using namespace std;

class Window
{
private:
	ALLEGRO_DISPLAY* display = NULL;
	int screen_width;
	int screen_height;
	int windowPositionX;
	int windowPositionY;
	const char* gameTitle;

public:
	Window(int screenWidth, int screenHeight, int windowPositionX, int windowPositionY, const char* gameTitle);
	~Window();

	void showWindow();


};

