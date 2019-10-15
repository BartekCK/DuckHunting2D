#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Button
{
private:
	ALLEGRO_BITMAP* buttonImage = NULL;

	int xPosition =0;
	int yPosition =0;
	int width =0;
	int height =0;
	const char* backgroundBitmap;

public:
	Button(const char* backgroundBitmap);
	~Button();

	void showButton();

	int getButtonWidth();
	int getButtonHeight();

	void setXposition(int x);
	void setYposition(int y);

	bool buttonClick(int x, int y);
};

