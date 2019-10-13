#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Button
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_BITMAP* buttonImage = NULL;
	int xPosition;
	int yPosition;
	const char* backgroundBitmap;

public:
	Button(int xPosition, int yPosition, const char* backgroundBitmap);
	~Button();

	void showButton();
	void setBackground();
};

