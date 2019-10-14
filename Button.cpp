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
	std::cout << "DESTRUKTOR Z BUTTON" << std::endl;
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
	
	std::cout << xPosition - (getButtonWidth() / 2) << std::endl;
	std::cout << xPosition + (getButtonWidth() / 2) << std::endl;
	std::cout << yPosition + (getButtonHeight() / 2) << std::endl;
	std::cout << yPosition - (getButtonHeight() / 2) << std::endl << std::endl;
	


	std::cout << xClick << std::endl;
	std::cout << yClick << std::endl << std::endl;
	

	if (xPosition - (getButtonWidth()/2) < xClick && xPosition + (getButtonWidth() / 2) > xClick
		&& yPosition - (getButtonHeight() / 2) < yClick && yPosition + (getButtonHeight()/2) > yClick) {
		return true;
	}
	return false;
}
