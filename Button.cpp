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
}


Button::~Button()
{
	al_destroy_bitmap(this->buttonImage);
}

void Button::showButton()
{
	al_draw_bitmap(this->buttonImage, this->xPosition, this->yPosition, 0);
}


int Button::getButtonWidth()
{
	return al_get_bitmap_width(this->buttonImage);
}

int Button::getButtonHeight()
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

bool Button::buttonClick(int xClick, int yClick)
{
	
	if (xPosition + getButtonWidth() > xClick && xPosition - getButtonWidth()< xClick
		&& yPosition + getButtonHeight() > yClick && yPosition - getButtonHeight() < yClick) {
		std::cout << "CLICK"<<std::endl;
		return true;
	}
	std::cout << "NO CLICK" << std::endl;
	return false;
}
