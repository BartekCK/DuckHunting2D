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
	
	delete gameLoop;
	al_uninstall_system();
	cout << "OBIEKT USUWANY" << endl;
}

void Stage::setScene(Scene *scene)
{
	this->scene = scene;
	
}

void Stage::show()
{
	gameLoop = new GameLoop(scene);
	gameLoop->startLoop();

}



