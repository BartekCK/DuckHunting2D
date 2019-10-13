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
	const char* gameTitle;
	int screen_width;
	int screen_height;
	

public:
	Scene(int screenWidth, int screenHeight, const char* gameTitle);
	virtual ~Scene();

	virtual void showWindow()=0;
	virtual void whereMouseClick(int x, int y)=0;
    void setBackground(const char* backgroundBitmap);
    virtual void createBackground()=0;

};

