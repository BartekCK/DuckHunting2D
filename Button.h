#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Node.h"


class Button:public Node
{

public:
	Button(const char* backgroundBitmap);
	~Button();

	void show()override;

	bool buttonClick(int x, int y);
};

