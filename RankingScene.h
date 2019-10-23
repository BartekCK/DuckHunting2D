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

public:
	RankingScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~RankingScene();
	void showWindow() override;
	void checkPoints();

};

