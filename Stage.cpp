#include "Stage.h"
#include "GameLoop.h"


Stage::Stage()
{
	//ALLEGRO INIT
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}
	al_init_image_addon();
	al_install_keyboard();
	
}

Stage::~Stage()
{
	//delete this->window;
	al_uninstall_system();
	cout << "OBIEKT USUWANY" << endl;
}

void Stage::windowConfigure(int screenWidth,int screenHeight, const char *gameTitle, const char * backgroundBitmap)
{
	this->scene = new Scene(screenWidth, screenHeight, gameTitle);
	this->scene->setBackground(backgroundBitmap);

}

void Stage::showScene()
{
	GameLoop *gameLoop = new GameLoop(scene);
	gameLoop->startLoop();

	delete gameLoop;
}



