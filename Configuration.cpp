#include "Configuration.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Configuration::Configuration()
{
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro!\n");
		exit(0);
	}

	this->display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		exit(0);
	}
}

Configuration::~Configuration()
{
	al_rest(5.0);
	al_destroy_display(this->display);
}

void Configuration::showDisplay()
{
	al_set_window_position(this->display, 100, 100);
	al_set_window_title(this->display, "My game");
	al_clear_to_color(al_map_rgb(25, 60, 120));
	al_flip_display();
}
