#pragma once
#include"Scene.h"
#include"Stage.h"
#include <iostream>

class GameScene:public Scene
{
	Stage* stage = NULL;

public:
	GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~GameScene();
	void showWindow() override;


};

