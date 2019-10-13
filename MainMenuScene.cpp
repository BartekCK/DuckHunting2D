#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle)
	:Scene(screenWidth, screenHeight, gameTitle)
{
	this->newGameButton = new Button((this->screen_width/2)-206, (this->screen_height / 2)-200, "images/buttons/buttonNewGame.png");
	this->endGameButton = new Button((this->screen_width / 2)- 206, (this->screen_height / 2)+250- 200, "images/buttons/buttonEndGame.png");
	newGameButton->setBackground();
	endGameButton->setBackground();
	
}

MainMenuScene::~MainMenuScene()
{
	delete newGameButton;
	delete endGameButton;
	cout << "DESKTRUKTOR Z MAIN_MENU_SCENE" << endl;
}

void MainMenuScene::showWindow()
{
	newGameButton->showButton();
	endGameButton->showButton();
	al_flip_display();
}

void MainMenuScene::createBackground()
{
	background = al_create_bitmap(this->screen_width, this->screen_height);

}
