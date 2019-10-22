#include "GroundDuck.h"



GroundDuck::GroundDuck(const char* backgroundBitmap, const int frames, const int levels)
	:Duck(backgroundBitmap,frames,levels)
{
	this->point = 50;

	if (temp % 2 == 0)
		xPosition = GetSystemMetrics(SM_CXSCREEN)+200;
	else
		xPosition = 0-200;
}

GroundDuck::~GroundDuck()
{
}

void GroundDuck::move()
{
	//MOVEMENT X
	if (xPosition == 0-200) {
		orientationX = true;
		this->shiftY = this->getBitmapHeight() / 2;
	}
	else if (xPosition == GetSystemMetrics(SM_CXSCREEN)+200) {
		orientationX = false;
		this->shiftY = 0;

	}
	if (orientationX)
		xPosition += this->moveSpeed;
	else
		xPosition -= this->moveSpeed;

	//ANIMATION
	this->shiftX += ((this->getBitmapWidth() / this->frames));
	if (this->shiftX >= this->getBitmapWidth())
		this->shiftX = 0;

}
