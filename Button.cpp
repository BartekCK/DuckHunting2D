#include "Button.h"

Button::Button(int xPosition, int yPosition, const char* backgroundBitmap)
	: xPosition(xPosition), yPosition(yPosition), backgroundBitmap(backgroundBitmap)
{
}


Button::~Button()
{
	al_destroy_bitmap(this->buttonImage);
}

void Button::showButton()
{
	al_draw_bitmap(buttonImage, this->xPosition, this->yPosition, 0);
}

void Button::setBackground()
{
	buttonImage = al_load_bitmap(this->backgroundBitmap);
	if (!buttonImage)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
	
}
