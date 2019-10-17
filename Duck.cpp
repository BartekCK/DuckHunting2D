#include "Duck.h"

Duck::Duck(const char* backgroundBitmap) : Node(backgroundBitmap)
{
}

void Duck::show()
{
	al_draw_bitmap(this->objectBitmap, this->xPosition, this->yPosition, 0);
}
