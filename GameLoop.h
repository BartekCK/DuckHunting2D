#pragma once

#include "Window.h"
class GameLoop
{
private:
	Window* window = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;

	bool done = false;
	const float FPS = 60;

public:
	GameLoop(Window * newWindow);
	~GameLoop();

	void startLoop();
};

