#include "Scene.h"

int Scene::gameTime = 0;
int Scene::tempGameTime = 0;



Scene::Scene(int screenWidth, int screenHeight, const char* gameTitle)
	: screen_width(screenWidth), screen_height(screenHeight),gameTitle(gameTitle){
	FPS[0] = 30;
	FPS[1] = 15;
	FPS[2] = 70;
	FPS[3] = 1;
	
}



void Scene::registerEvent()
{
	this->event_queue = al_create_event_queue();

	al_register_event_source(this->event_queue, al_get_keyboard_event_source());
	al_register_event_source(this->event_queue, al_get_mouse_event_source());

	for (int i = 0; i < 4; i++) {
		timer[i] = al_create_timer(1.0 / FPS[i]);
		al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer[i]));

	}
	
	
	
}

void Scene::deleteEvent()
{
	for (int i = 0; i < 4; i++) {
		al_destroy_timer(timer[i]);
	}

	
	al_destroy_event_queue(this->event_queue);
}

void Scene::startTimers()
{
	for(int i=0;i<4;i++)
		al_start_timer(this->timer[i]);

}

void Scene::stopTimers()
{
	for (int i = 0; i < 4; i++)
		al_stop_timer(this->timer[i]);
}

Scene::~Scene()
{

	al_destroy_bitmap(this->background);


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