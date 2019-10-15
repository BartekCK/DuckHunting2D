#include "Button.h"

Button::Button(const char* backgroundBitmap)
	: backgroundBitmap(backgroundBitmap)
{
	this->buttonImage = al_load_bitmap(this->backgroundBitmap);
	if (!buttonImage)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}

	this->width = al_get_bitmap_width(this->buttonImage);
	this->height = al_get_bitmap_height(this->buttonImage);
}


Button::~Button()
{
	al_destroy_bitmap(this->buttonImage);
	std::cout << "DESTRUKTOR Z BUTTON" << std::endl;
}

void Button::showButton()
{
	al_draw_bitmap(this->buttonImage, this->xPosition, this->yPosition, 0);
}


int Button::getButtonWidth()
{
	return this->width;
}

int Button::getButtonHeight()
{
	return this->height;
}

void Button::setXposition(int x)
{
	this->xPosition = x;
}

void Button::setYposition(int y)
{
	this->yPosition = y;
}

bool Button::buttonClick(int xClick, int yClick)
{
	if (xClick > xPosition&& xClick < xPosition + width &&
		yClick > yPosition && yClick < yPosition + height) {
		return true;
	}
	return false;
}
