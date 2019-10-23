#pragma once

#include <sstream>
#include <iostream>

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>

class Text
{
	ALLEGRO_FONT* font = NULL;
	int best = 0;
public:

	Text();
	~Text();
	void showPoint(int point, int screen_width);
	void showPoint(int point, int screen_width, int screen_height);
	void showTime(int time);
	void gameEndInformation(ALLEGRO_DISPLAY* display, int point);
	void bestRanking15(int screen_width, int screen_height);
	void bestRanking30(int screen_width, int screen_height);
	void bestRanking60(int screen_width, int screen_height);

};

