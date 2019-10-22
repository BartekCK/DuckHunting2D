#pragma once

#include"duck.h"

class SuperDuck:public Duck
{
public:
	SuperDuck(const char* backgroundBitmap, const int frames, const int levels);
	~SuperDuck();

	void move() override;
};

