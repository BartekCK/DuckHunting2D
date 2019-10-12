#include "Configuration.h"
#include "GameLoop.h"


Configuration::Configuration()
{
	//ALLEGRO INIT
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}
	al_init_image_addon();
	al_install_keyboard();
	
}

Configuration::~Configuration()
{
	//delete this->window;
	al_uninstall_system();
	cout << "OBIEKT USUWANY" << endl;
}

void Configuration::windowConfigure(int screenWidth,int screenHeight, const char *gameTitle, const char * backgroundBitmap)
{
	this->window = new Window(screenWidth, screenHeight, gameTitle);
	this->window->setBackground(backgroundBitmap);

}

void Configuration::showScene()
{
	GameLoop *gameLoop = new GameLoop(window);
	gameLoop->startLoop();

	delete gameLoop;
}



