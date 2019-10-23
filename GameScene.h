#pragma once
#include"Scene.h"
#include"Stage.h"
#include"Duck.h"
#include"Path.h"
#include"Hunter.h"
#include <iostream>
#include"GroundDuck.h"
#include"SuperDuck.h"
#include"Text.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

constexpr auto COUNT_DUCKS = 4;
constexpr auto COUNT__GROUND_DUCKS = 2;
constexpr auto COUNT_SUPER_DUCKS = 2;

class GameScene:public Scene
{
	Stage* stage = NULL;
	Duck* duck[COUNT_DUCKS];
	GroundDuck* groundDuck[COUNT__GROUND_DUCKS];
	SuperDuck* superDuck[COUNT_SUPER_DUCKS];

	ALLEGRO_SAMPLE* soundEffect = NULL;
	ALLEGRO_SAMPLE* song = NULL;
	ALLEGRO_SAMPLE_INSTANCE* songInstance = NULL;

public:
	GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage);
	~GameScene();
	void showWindow() override;


};

