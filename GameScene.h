#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Path.h"
#include"Hunter.h"
#include"GroundDuck.h"
#include"SuperDuck.h"
#include"Text.h"
#include"Music.h"
#include <vector>
#include <sstream>

constexpr auto COUNT_DUCKS = 4;
constexpr auto COUNT__GROUND_DUCKS = 2;
constexpr auto COUNT_SUPER_DUCKS = 2;

class GameScene:public Scene
{
	Stage* stage = NULL;
	
	vector <Duck*> duckList;



public:
	GameScene(Stage* stage);
	~GameScene();
	void showWindow() override;



};

