#pragma 
#include"Duck.h"

class GroundDuck:public Duck
{
public:
	GroundDuck(const char* backgroundBitmap, const int frames, const int levels);
	~GroundDuck();
	void move() override;
};

