#include "Duck.h"

int Duck::temp = 100;



Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{
	point = 100;
	Path path;
	startPositionY = temp;
	temp += 161;

	if (temp % 2 == 0) {
		xPosition = GetSystemMetrics(SM_CXSCREEN);
	}
	else {
		xPosition = 0;
	}
		

	yPosition = startPositionY;
	explosionBitmap = al_load_bitmap(path.EXPLOSION);

}

Duck::~Duck()
{
	al_destroy_bitmap(explosionBitmap);
	cout << "DESTRUKTOR Z DUCK" << endl;

}


void Duck::show()
{
	if (staticBitmap!=0)
	{
		staticBitmap--;
		al_draw_bitmap(explosionBitmap, xPosition, yPosition, 0);
	}
	else {
		al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
	}
}

void Duck::move(ALLEGRO_EVENT events)
{
	if (events.timer.source == engine->timmerVector[0]) {
	
		//MOVEMENT X
		if (xPosition <= 0) {
			orientationX = true;
			this->shiftY = this->getBitmapHeight() / 2;


		}
		else if (xPosition > GetSystemMetrics(SM_CXSCREEN)) {
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
	

}

bool Duck::checkShoot(float xShot, float yShot)
{
	

	if (xShot > xPosition&& xShot < xPosition + bitmapWidth/frames &&
		yShot > yPosition&& yShot < yPosition + bitmapHeight/levels) {
		staticBitmap = 10;
		return true;
	}
	else
		return false;
	
}

int Duck::getPoint()
{
	return this->point;
}
