#include "Scene.h"

int Scene::gameTime = 0;
int Scene::tempGameTime = 0;
int Scene::screen_width = GetSystemMetrics(SM_CXSCREEN);
int Scene::screen_height = GetSystemMetrics(SM_CYSCREEN);



Scene::Scene()
{


	
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