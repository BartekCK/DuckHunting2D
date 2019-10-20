#include "Duck.h"

int Duck::temp = 100;

Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{
	
	startPositionY = temp;
	temp += 161;

	if (temp % 2 == 0)
		xPosition = GetSystemMetrics(SM_CXSCREEN);
	else
		xPosition = 0;

	yPosition = startPositionY;
}


void Duck::show()
{
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->width / frames, this->height / levels, this->xPosition, this->yPosition,0);
}

void Duck::move()
{

	//MOVEMENT X
	if (xPosition == 0) {
		orientationX = true;
		this->shiftY = this->getHeight() / 2;
	}
	else if (xPosition == GetSystemMetrics(SM_CXSCREEN)) {
		orientationX = false;
		this->shiftY = 0;

	}
	if (orientationX)
		xPosition += this->moveSpeed;
	else
		xPosition -= this->moveSpeed;

	//MOVEMENT Y
	if (yPosition == (startPositionY - 100))
		orientationY = true;
	else if (yPosition == (startPositionY + 100))
		orientationY = false;

	if (orientationY)
		yPosition += this->moveSpeed;
	else
		yPosition -= this->moveSpeed;
	
	
	//ANIMATION
	this->shiftX += ((this->getWidth() / this->frames));
	if (this->shiftX >= this->getWidth())
		this->shiftX = 0;

}

