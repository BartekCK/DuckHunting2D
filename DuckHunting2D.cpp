// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Configuration.h"

using namespace std;

int main()
{
	
	Configuration *configuration = new Configuration(800, 600, 10, 10, "Hello world");
	configuration->showWindow();
	delete configuration;
	return 0;
}

