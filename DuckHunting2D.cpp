// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Stage.h"
#include "Path.h"
#include "MainMenuScene.h"

using namespace std;

int main()
{
	Path path;
	Stage *stage = new Stage();
	Scene* scene = new MainMenuScene(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Duck hunting");
	scene->setBackground(path.BACKGROUND_MAIN_MENU);

	stage->setScene(scene);
	stage->show();

	delete stage;
	return 0;
}

