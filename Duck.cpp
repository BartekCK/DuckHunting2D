#include "Duck.h"

Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{
}

void Duck::show()
{
	int shiftX = 0, shiftY = 0;
	//al_draw_bitmap(this->objectBitmap, this->xPosition, this->yPosition, 0);

	al_draw_bitmap_region(this->objectBitmap, shiftX, shiftY, this->width / frames, this->height / levels, this->xPosition, this->yPosition,NULL);
}
