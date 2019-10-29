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

	

	const char* gameTitle;
	int screen_width;
	int screen_height;
	bool done = false;
	static int gameTime;
	static int tempGameTime;

	Engine* engine = Engine::getInstance();


public:
	Scene(int screenWidth, int screenHeight, const char* gameTitle);
	virtual ~Scene();

	virtual void showWindow()=0;
    void setBackground(const char* backgroundBitmap);

private:

	ALLEGRO_BITMAP* load_bitmap_at_size(const char* filename, int w, int h);
	
};

