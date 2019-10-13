#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
class Button
{
private:
	ALLEGRO_BITMAP* buttonImage = NULL;

	int xPosition =0;
	int yPosition =0;
	const char* backgroundBitmap;

public:
	Button(const char* backgroundBitmap);
	~Button();

	void showButton();
	void setButtonImage();

	double getButtonWidth();
	double getButtonHeight();

	void setXposition(int x);
	void setYposition(int y);
};

