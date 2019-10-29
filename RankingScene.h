#pragma once
#include"Scene.h"
#include "Stage.h"
#include "Button.h"
#include <sstream>

class RankingScene:public Scene
{
	Stage* stage = NULL;
	Button* button = NULL;
	string bestPoints[3];
	void checkPoints();

public:
	RankingScene( Stage* stage);
	~RankingScene();
	void showWindow() override;

};

