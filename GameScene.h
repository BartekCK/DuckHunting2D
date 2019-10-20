#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Duck.h"
#include"Path.h"
#include <iostream>

constexpr auto COUNT_DUCKS = 4;

class GameScene:public Scene
{
	Stage* stage = NULL;
	Duck* duck[COUNT_DUCKS];

public:
	GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~GameScene();
	void showWindow() override;


};

