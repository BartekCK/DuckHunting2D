#pragma once
#include "Scene.h"
#include "Button.h"
#include "Path.h"

class MainMenuScene:public Scene
{
private:
	Button *newGameButton = NULL;
	Button *endGameButton = NULL;
	
public:
	MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle);
	virtual ~MainMenuScene();

	void showWindow();
	void createBackground () override;
	void whereMouseClick(int x, int y);

};

