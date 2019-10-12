#include "Configuration.h"


Configuration::Configuration(int screenWidth, int screenHeight, int windowPositionX, int windowPositionY, const char* gameTitle)
{
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}
	this->window = new Window(screenWidth, screenHeight, windowPositionX, windowPositionY, gameTitle);

	
}

Configuration::~Configuration()
{
	al_rest(5.0);
	delete this->window;
	cout << "OBIEKT USUWANY" << endl;
}

void Configuration::showWindow()
{
	this->window->showWindow();

}

