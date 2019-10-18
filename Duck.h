#pragma once
#include "Node.h"


class Duck:public Node
{
private:
	const int frames;
	const int levels;
public:
	Duck(const char* backgroundBitmap, const int frames, const int levels);
	void show() override;
};

