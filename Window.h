#pragma once

#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Window
{
private:
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_BITMAP* background = NULL;
	int screen_width;
	int screen_height;
	const char* gameTitle;

public:
	Window(int screenWidth, int screenHeight, const char* gameTitle);
	~Window();

	void showWindow();
	void setBackground(const char* backgroundBitmap);

};

