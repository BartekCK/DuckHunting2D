#pragma once
#include "Scene.h"
#include "Button.h"
#include "Path.h"
#include "Stage.h"

class MainMenuScene:public Scene
{
private:
	Button *newGameButton = NULL;
	Button *endGameButton = NULL;
	Stage* stage = NULL;
	
public:
	MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle, Stage *stage);
	virtual ~MainMenuScene();

	void showWindow() override;

};

