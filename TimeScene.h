#pragma once
#include"Stage.h"
#include"Button.h"
#include"Path.h"
class TimeScene :public Scene
{
	Button* button[3];
	Stage* stage = NULL;


public:
	TimeScene(Stage* stage);
	~TimeScene();
	void showWindow() override;

};

