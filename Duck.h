#pragma once
#include "Node.h"


class Duck:public Node
{
public:
	Duck(const char* backgroundBitmap);
	void show() override;
};

