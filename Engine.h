#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <Windows.h>


class Engine
{
	ALLEGRO_DISPLAY* display = NULL;
	static Engine* instance;
	Engine();
	~Engine();
public:
	static Engine* getInstance();
	ALLEGRO_DISPLAY * returnDisplay();
};

