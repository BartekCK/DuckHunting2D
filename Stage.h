#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Scene.h"
#include "GameLoop.h"

class Stage {
private:
	Scene *scene = NULL;
	GameLoop *gameLoop = NULL;
	
public:
	Stage();
	~Stage();


	void setScene(int screenWidth, int screenHeight, const char* gameTitle, const char* backgroundBitmap);
	void show();
};

