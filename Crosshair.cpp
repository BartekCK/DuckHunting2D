#include "Crosshair.h"

Crosshair::Crosshair(ALLEGRO_DISPLAY* display):display(display)
{
	Path path;
	this->objectBitmap = al_load_bitmap(path.CROSSHAIR);
	if (!objectBitmap)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
	al_hide_mouse_cursor(this->display);
	this->bitmapWidth = al_get_bitmap_width(this->objectBitmap);
	this->bitmapHeight = al_get_bitmap_height(this->objectBitmap);
}

Crosshair::~Crosshair()
{
	al_destroy_bitmap(this->objectBitmap);
	al_show_mouse_cursor(this->display);

}

void Crosshair::showCross(float x, float y)
{
	al_draw_bitmap(this->objectBitmap, x- (bitmapWidth/2), y- (bitmapHeight/2), NULL);
}

void Crosshair::shot(float xShot, float yShot, Duck duck[])
{
	for (int i = 0; i < 5; i++) {
		if (xShot > duck[i].getXposition() && xShot < duck[i].getXposition() + duck[i].getBitmapWidth() &&
			yShot > duck[i].getYposition() && yShot < duck[i].getYposition() + duck[i].getBitmapHeight()) {
			cout << "TRAFIONO" << endl;
			
			
		}
		else
		{
			cout << "NIE TRAFIONO" << endl;
		}
	}


	
}

/*bool Button::buttonClick(int xClick, int yClick)
{
	if (xClick > xPosition&& xClick < xPosition + bitmapWidth &&
		yClick > yPosition&& yClick < yPosition + bitmapHeight) {
		return true;
	}
	return false;
}
*/
