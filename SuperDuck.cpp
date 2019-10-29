#include "SuperDuck.h"

SuperDuck::SuperDuck(const char* backgroundBitmap, const int frames, const int levels) 
	:Duck(backgroundBitmap, frames, levels)
{
	this->point = 200;
	if (temp % 2 == 0) {
		yPosition = GetSystemMetrics(SM_CYSCREEN);
		xPosition = GetSystemMetrics(SM_CXSCREEN) / 10;
	}
	else {
		yPosition = 0;
		xPosition = GetSystemMetrics(SM_CXSCREEN) -( GetSystemMetrics(SM_CXSCREEN) / 10);

	}

	startPositionY = yPosition;
}

SuperDuck::~SuperDuck()
{
}

void SuperDuck::move(ALLEGRO_EVENT events)
{

	if (events.timer.source == engine->timmerVector[2]) {
		//MOVEMENT Y

		if (yPosition == 0)
			orientationY = true;
		else if (yPosition == GetSystemMetrics(SM_CYSCREEN))
			orientationY = false;

		if (orientationY)
			yPosition += this->moveSpeed;
		else
			yPosition -= this->moveSpeed;


		//ANIMATION
		this->shiftX += ((this->getBitmapWidth() / this->frames));
		if (this->shiftX >= this->getBitmapWidth())
			this->shiftX = 0;

	}
}
