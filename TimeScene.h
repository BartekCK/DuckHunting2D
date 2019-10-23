#pragma once
#include"Stage.h"
#include"Scene.h"
#include"Button.h"
#include"Path.h"
class TimeScene :public Scene
{
	Button* button;
	Stage* stage = NULL;


public:
	TimeScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~TimeScene();
	void showWindow() override;

};

