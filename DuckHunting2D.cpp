// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Configuration.h"
#include "Path.h"

using namespace std;

int main()
{
	Path path;
	Configuration *configuration = new Configuration();
	configuration->windowConfigure(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), "Duck hunting",path.BACKGROUND_MAIN_MENU);
	configuration->showScene();

	delete configuration;
	return 0;
}

