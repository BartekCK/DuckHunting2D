#include "Button.h"

Button::Button(const char* backgroundBitmap)
	: backgroundBitmap(backgroundBitmap)
{
}


Button::~Button()
{
	al_destroy_bitmap(this->buttonImage);
}

void Button::showButton()
{
	al_draw_bitmap(this->buttonImage, this->xPosition, this->yPosition, 0);
}

void Button::setButtonImage()
{
	this->buttonImage = al_load_bitmap(this->backgroundBitmap);
	if (!buttonImage)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
	
}

double Button::getButtonWidth()
{
	return al_get_bitmap_width(this->buttonImage);
}

double Button::getButtonHeight()
{
	return al_get_bitmap_height(this->buttonImage);
}

void Button::setXposition(int x)
{
	this->xPosition = x;
}

void Button::setYposition(int y)
{
	this->yPosition = y;
}
