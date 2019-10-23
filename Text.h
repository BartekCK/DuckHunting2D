#pragma once

#include <sstream>
#include <iostream>

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>

class Text
{
	ALLEGRO_FONT* font = NULL;
public:

	Text();
	~Text();
	void showPoint(int point, int screen_width);
	void showTime(int time);
	void gameEndInformation(ALLEGRO_DISPLAY* display, int point);

};

