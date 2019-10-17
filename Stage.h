#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Scene.h"

class Stage {
private:
	Scene *menuScene = NULL;
	Scene *gameScene = NULL;
	
public:
	Stage();
	~Stage();


	void setMenuScene(Scene *scene);
	void setGameScene(Scene *scene);
	void showMenu();
	void showGame();
};

