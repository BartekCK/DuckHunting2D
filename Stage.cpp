#include "Stage.h"

Stage::Stage()
{
	//ALLEGRO INIT
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
}

Stage::~Stage()
{
	
	delete menuScene;
	delete gameScene;

	al_uninstall_system();
	cout << "DESKTRUKTOR ZE STAGE" << endl;
}

void Stage::setMenuScene(Scene *scene)
{
	this->menuScene = scene;
	
}

void Stage::setGameScene(Scene* scene)
{
	this->gameScene = scene;

}

void Stage::showMenu()
{
	this->menuScene->showWindow();

}

void Stage::showGame()
{
	this->gameScene->showWindow();
}



