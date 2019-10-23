#pragma once


#include <iostream>
#include <allegro5/allegro.h>
#include "Scene.h"

class Stage {
private:
	Scene *menuScene = NULL;
	Scene *gameScene = NULL;
	Scene *timeScene = NULL;
	Scene *rankingScene = NULL;
	
public:
	Stage();
	~Stage();


	void setMenuScene(Scene *scene);
	void setGameScene(Scene *scene);
	void setTimeScene(Scene *scene);
	void setRankingScene(Scene *scene);

	void showMenu();
	void showGame();
	void showTimers();
	void showRanking();
};

