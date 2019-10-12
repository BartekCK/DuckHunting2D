#include "Window.h"



Window::Window(int screenWidth, int screenHeight, int windowPositionX, int windowPositionY, const char* gameTitle)
	: screen_width(screenWidth), screen_height(screenHeight), windowPositionX(windowPositionX),
	windowPositionY(windowPositionY), gameTitle(gameTitle){

	this->display = al_create_display(screenWidth, screenHeight);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		exit(0);
	}
}

Window::~Window()
{
	al_destroy_display(this->display);
}

void Window::showWindow()
{
	al_set_window_position(this->display, windowPositionX, windowPositionY);
	al_set_window_title(this->display,gameTitle);
	al_clear_to_color(al_map_rgb(25, 60, 120));
	al_flip_display();
}
