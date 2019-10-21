#include "Stage.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

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
	al_install_audio();
	al_init_acodec_addon();
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



