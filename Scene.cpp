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

	this->timer = al_create_timer(1.0 / FPS);
	this->event_queue = al_create_event_queue();

	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
	al_register_event_source(this->event_queue, al_get_keyboard_event_source());
	al_register_event_source(this->event_queue, al_get_mouse_event_source());
	al_start_timer(this->timer);

}

Scene::~Scene()
{
	al_destroy_display(this->display);
	al_destroy_bitmap(this->background);

	al_destroy_timer(this->timer);
	al_destroy_event_queue(this->event_queue);

	cout << "DESKTRUKTOR ZE SCENE" << endl;

}

void Scene::setBackground(const char* backgroundBitmap)
{
	this->background = al_create_bitmap(this->screen_width, this->screen_height);
	this->background = al_load_bitmap(backgroundBitmap);
	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
	al_draw_bitmap(background, 0, 0, 0);
}

