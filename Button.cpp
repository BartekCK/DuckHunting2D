#include "Button.h"

Button::Button(const char* backgroundBitmap)
	: Node(backgroundBitmap)
{
	
}


Button::~Button()
{
	std::cout << "DESTRUKTOR Z BUTTON" << std::endl;
}

void Button::show()
{
	al_draw_bitmap(this->objectBitmap, this->xPosition, this->yPosition, 0);
}


bool Button::buttonClick(int xClick, int yClick)
{
	if (xClick > xPosition&& xClick < xPosition + width &&
		yClick > yPosition && yClick < yPosition + height) {
		return true;
	}
	return false;
}
