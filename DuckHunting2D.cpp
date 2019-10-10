// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Configuration.h"

using namespace std;

int main()
{
	Configuration *configuration = new Configuration();
	configuration->showDisplay();
	delete configuration;
	return 0;
}

