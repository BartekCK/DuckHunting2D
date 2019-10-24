#include "Text.h"
#include "Path.h"


Text::Text()
{
	Path path;
	this->font = al_load_font(path.MY_FONT, 40, NULL);

}

Text::~Text()
{
	al_destroy_font(font);
	std::cout << "DESTRuKTOR Z TEXT" << std::endl;
}

void Text::showPoint(int point,int screen_width)
{
	std::stringstream pointsStr;
	pointsStr << "Punkty: \n" << point;
	al_draw_text(this->font, al_map_rgb(255, 0, 0), screen_width-180, 50, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());
	
}

void Text::showPoint(int point, int screen_width,int screen_height)
{
	std::stringstream pointsStr;
	pointsStr << "Zdobyte punkty: \n" << point;
	al_draw_text(this->font, al_map_rgb(255, 0, 0), screen_width, screen_height, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());

}

void Text::showTime(int time)
{
	std::stringstream pointsStr;

	pointsStr << "Czas: \n" << time;
	
	al_draw_text(this->font, al_map_rgb(255, 0, 0), 0 + 130, 50, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());

}

void Text::gameEndInformation(ALLEGRO_DISPLAY * display,int point)
{
	std::stringstream str;
	str << point;
	al_show_native_message_box(display, "Informacja", "Uzysales punktow:", str.str().c_str(), NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL);

}

void Text::bestRanking15(string best, int screen_width, int screen_height)
{
	std::stringstream pointsStr;
	pointsStr << "Najlepszy wynik na 15 sekund :"<<best;
	al_draw_text(this->font, al_map_rgb(255, 0, 0), screen_width, screen_height, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());
}

void Text::bestRanking30(string best, int screen_width, int screen_height)
{
	std::stringstream pointsStr;
	pointsStr << "Najlepszy wynik na 30 sekund :" << best;
	al_draw_text(this->font, al_map_rgb(255, 0, 0), screen_width, screen_height, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());
}

void Text::bestRanking60(string best, int screen_width, int screen_height)
{
	std::stringstream pointsStr;
	pointsStr << "Najlepszy wynik na 60 sekund :" << best;
	al_draw_text(this->font, al_map_rgb(255, 0, 0), screen_width, screen_height, ALLEGRO_ALIGN_CENTER, pointsStr.str().c_str());
}
