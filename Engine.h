#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

class Engine
{
	ALLEGRO_DISPLAY* display = NULL;

	int FPS[4];

	static Engine* instance;
	Engine();
public:
	~Engine();

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	vector <ALLEGRO_TIMER*> timmerVector;


	static Engine* getInstance();
	ALLEGRO_DISPLAY * returnDisplay();
	void startTimers();
	void stopTimers();
};

