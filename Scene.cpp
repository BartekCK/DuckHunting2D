#include "Scene.h"



Scene::Scene(int screenWidth, int screenHeight, const char* gameTitle)
	: screen_width(screenWidth), screen_height(screenHeight),gameTitle(gameTitle){

	this->display = al_create_display(screenWidth, screenHeight);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		exit(0);
	}
	al_set_new_display_flags(ALLEGRO_FULLSCREEN | ALLEGRO_MAXIMIZED);
	al_set_window_title(this->display, gameTitle);
}

Scene::~Scene()
{
	al_destroy_display(this->display);
	al_destroy_bitmap(this->background);
}

void Scene::setBackground(const char* backgroundBitmap)
{
	background = al_create_bitmap(this->screen_width, this->screen_height);
	background = al_load_bitmap(backgroundBitmap);
	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
	al_draw_bitmap(background, 0, 0, 0);
}

void Scene::showWindow()
{
	al_flip_display();
}
