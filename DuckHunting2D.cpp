// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Stage.h"
#include "Path.h"

using namespace std;

int main()
{
	Path path;
	Stage *stage = new Stage();
	stage->windowConfigure(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Duck hunting",path.BACKGROUND_MAIN_MENU);
	stage->showScene();

	delete stage;
	return 0;
}

