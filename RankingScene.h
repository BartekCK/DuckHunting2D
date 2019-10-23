#pragma once
#include"Scene.h"
#include "Stage.h"
#include "Button.h"

class RankingScene:public Scene
{
	Stage* stage = NULL;
	Button* button = NULL;

public:
	RankingScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~RankingScene();
	void showWindow() override;

};

