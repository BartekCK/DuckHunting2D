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


	void setScene(Scene *scene);
	void show();
};

