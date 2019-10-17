// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Stage.h"
#include "Path.h"
#include "MainMenuScene.h"
#include "GameScene.h"

using namespace std;

int main()
{
	Path path;
	Stage *stage = new Stage();
	Scene* sceneMenu = new MainMenuScene(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Duck hunting", stage);
	Scene* sceneGame = new GameScene(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Duck hunting", stage);
	
	sceneMenu->setBackground(path.BACKGROUND_MAIN_MENU);
	sceneGame->setBackground(path.BACKGROUND_GAME);

	stage->setMenuScene(sceneMenu);
	stage->setGameScene(sceneGame);

	stage->showMenu();

	delete stage;
	return 0;
}

