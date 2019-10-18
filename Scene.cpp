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

	
	//registerEvent();
}

void Scene::registerEvent()
{
	this->event_queue = al_create_event_queue();

	al_register_event_source(this->event_queue, al_get_keyboard_event_source());
	al_register_event_source(this->event_queue, al_get_mouse_event_source());

	//TIMER JEST PODEJRZANY !!!
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
}

void Scene::deleteEvent()
{
	al_destroy_timer(timer);
	al_destroy_event_queue(this->event_queue);
}

Scene::~Scene()
{

	al_destroy_display(this->display);
	al_destroy_bitmap(this->background);

	//deleteEvent();

	cout << "DESKTRUKTOR ZE SCENE" << endl;

}

void Scene::setBackground(const char* backgroundBitmap)
{
	
	background = load_bitmap_at_size(backgroundBitmap, this->screen_width, this->screen_height);
	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		exit(0);
	}
}



ALLEGRO_BITMAP* Scene::load_bitmap_at_size(const char* filename, int w, int h)
{
	ALLEGRO_BITMAP* resized_bmp, * loaded_bmp, * prev_target;

	resized_bmp = al_create_bitmap(w, h);
	if (!resized_bmp) return NULL;

	loaded_bmp = al_load_bitmap(filename);
	if (!loaded_bmp)
	{
		al_destroy_bitmap(resized_bmp);
		return NULL;
	}

	prev_target = al_get_target_bitmap();
	al_set_target_bitmap(resized_bmp);

	al_draw_scaled_bitmap(loaded_bmp,
		0, 0,                                // source origin
		al_get_bitmap_width(loaded_bmp),     // source width
		al_get_bitmap_height(loaded_bmp),    // source height
		0, 0,                                // target origin
		w, h,                                // target dimensions
		0                                    // flags
	);

	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(loaded_bmp);

	return resized_bmp;

}