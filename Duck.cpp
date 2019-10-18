#include "Duck.h"

Duck::Duck(const char* backgroundBitmap, const int frames, const int levels) : Node(backgroundBitmap),frames(frames),levels(levels)
{


}

void Duck::show()
{
	

	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->width / frames, this->height / levels, this->xPosition, this->yPosition,0);
}
