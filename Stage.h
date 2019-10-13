#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Scene.h"

class Stage {
private:
	Scene *scene = NULL;
	
public:
	Stage();
	~Stage();


	void windowConfigure(int screenWidth, int screenHeight, const char* gameTitle, const char* backgroundBitmap);
	void show();
};

