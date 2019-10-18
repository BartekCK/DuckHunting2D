#include "Duck.h"

Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{


}

void Duck::show()
{
	

	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->width / frames, this->height / levels, this->xPosition, this->yPosition,0);
}

void Duck::move(int screen_width, int screen_height)
{

	
	enum direction { LEFT, RIGHT };

	if (xPosition == 0) {
		orientationX = true;
		this->shiftY = this->getHeight() / 2;
	}
	else if (xPosition == screen_width) {
		orientationX = false;
		this->shiftY = 0;

	}
	if (orientationX)
		xPosition += this->moveSpeed;
	else
		xPosition -= this->moveSpeed;


	if (orientationY)
		yPosition += this->moveSpeed;
	else
		yPosition -= this->moveSpeed;
	if (yPosition == 0)
		orientationY = true;
	if (yPosition == screen_height / 4)
		orientationY = false;

	this->shiftX += ((this->getWidth() / this->frames));
	if (this->shiftX >= this->getWidth())//JEST JAKBY O JEDNA KLATE ZA DUZO
		this->shiftX = 0;

}

