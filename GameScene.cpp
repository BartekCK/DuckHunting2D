#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
}

void GameScene::showWindow()
{
	al_draw_bitmap(background, 0, 0, 0);
	cout << "SCENA Z GRY" << endl;
}
