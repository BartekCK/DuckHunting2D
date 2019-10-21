#include "Duck.h"

int Duck::temp = 100;



Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{
	Path path;
	startPositionY = temp;
	temp += 161;

	if (temp % 2 == 0)
		xPosition = GetSystemMetrics(SM_CXSCREEN);
	else
		xPosition = 0;

	yPosition = startPositionY;
	explosionBitmap = al_load_bitmap(path.EXPLOSION);

}

Duck::~Duck()
{
	al_destroy_bitmap(explosionBitmap);

}


void Duck::show()
{
	if (staticBitmap)
	{
		staticBitmap = false;
		al_draw_bitmap(explosionBitmap, xPosition, yPosition, 0);
	}
	else {
		al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
	}
}

void Duck::move()
{

	//MOVEMENT X
	if (xPosition == 0) {
		orientationX = true;
		this->shiftY = this->getBitmapHeight() / 2;
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
	this->shiftX += ((this->getBitmapWidth() / this->frames));
	if (this->shiftX >= this->getBitmapWidth())
		this->shiftX = 0;

}

bool Duck::checkShoot(float xShot, float yShot, int i)
{
	

	if (xShot > xPosition&& xShot < xPosition + bitmapWidth/frames &&
		yShot > yPosition&& yShot < yPosition + bitmapHeight/levels) {
		staticBitmap = true;
		return true;
	}
	else
		return false;
	
}
