#pragma once

#include <iostream>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Path.h"
#include "Engine.h"

using namespace std;

class Scene
{
protected:
	ALLEGRO_BITMAP* background = NULL;
	Engine* engine = Engine::getInstance();

	static int screen_width;
	static int screen_height;
	static int gameTime;
	static int tempGameTime;

	bool done = false;

public:
	Scene();
	virtual ~Scene();

	virtual void showWindow()=0;
    void setBackground(const char* backgroundBitmap);

private:

	ALLEGRO_BITMAP* load_bitmap_at_size(const char* filename, int w, int h);
	
};

