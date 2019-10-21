#pragma once

#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Scene
{
protected:
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_BITMAP* background = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;

	const char* gameTitle;
	int screen_width;
	int screen_height;
	bool done = false;
	const int FPS = 10;

public:
	Scene(int screenWidth, int screenHeight, const char* gameTitle);
	virtual ~Scene();

	virtual void showWindow()=0;
    void setBackground(const char* backgroundBitmap);
	void registerEvent();
	void deleteEvent();

private:

	ALLEGRO_BITMAP* load_bitmap_at_size(const char* filename, int w, int h);
	
};

