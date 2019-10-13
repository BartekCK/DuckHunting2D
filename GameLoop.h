#pragma once

#include "Scene.h"
#include "Button.h"
#include "MainMenuScene.h"
class GameLoop
{
private:
	Scene* scene = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;

	bool done = false;
	const float FPS = 60;

public:
	GameLoop(Scene * newScene);
	~GameLoop();

	void startLoop();
};

