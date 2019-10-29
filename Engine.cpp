#include "Engine.h"
Engine* Engine::instance = 0;

Engine::Engine()
{
	this->display = al_create_display(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		exit(0);
	}
	al_set_new_display_flags(ALLEGRO_FULLSCREEN | ALLEGRO_MAXIMIZED);
	al_set_window_title(this->display,"Game");
}

Engine::~Engine()
{
	al_destroy_display(this->display);
}

Engine* Engine::getInstance()
{
	if (instance == 0)
	{
		instance = new Engine();
	}

	return instance;
}

ALLEGRO_DISPLAY* Engine::returnDisplay()
{
	return display;
}

