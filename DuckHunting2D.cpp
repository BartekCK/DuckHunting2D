// DuckHunting2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stage.h"
#include "Path.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "TimeScene.h"
#include "RankingScene.h"
#include "Engine.h"

using namespace std;

int main()
{
	Path path;
	Stage *stage = new Stage();
	Scene* sceneMenu = new MainMenuScene(stage);
	Scene* sceneGame = new GameScene( stage);
	Scene* sceneTime = new TimeScene( stage);
	Scene* sceneRanking = new RankingScene( stage);
	
	sceneMenu->setBackground(path.BACKGROUND_MAIN_MENU);
	sceneGame->setBackground(path.BACKGROUND_GAME);
	sceneTime->setBackground(path.BACKGROUND_MAIN_MENU);
	sceneRanking->setBackground(path.BACKGROUND_RANKING);

	stage->setMenuScene(sceneMenu);
	stage->setGameScene(sceneGame);
	stage->setTimeScene(sceneTime);
	stage->setRankingScene(sceneRanking);

	stage->showMenu();

	Engine* engine = Engine::getInstance();
	delete engine;
	delete stage;
	return 0;
}

