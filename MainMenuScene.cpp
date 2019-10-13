#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle)
	:Scene(screenWidth, screenHeight, gameTitle)
{
	Path path;
	this->newGameButton = new Button(path.BUTTON_NEW_GAME);
	this->endGameButton = new Button(path.BUTTON_END_GAME);

	this->newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getButtonWidth()/2));
	this->newGameButton->setYposition((this->screen_height / 2) -(this->newGameButton->getButtonHeight() / 2)-100);

	this->endGameButton->setXposition((this->screen_width / 2) - (this->endGameButton->getButtonWidth() / 2));
	this->endGameButton->setYposition((this->screen_height / 2) - (this->endGameButton->getButtonHeight() / 2)+100);
	
}

MainMenuScene::~MainMenuScene()
{
	delete newGameButton;
	delete endGameButton;
	cout << "DESKTRUKTOR Z MAIN_MENU_SCENE" << endl;
}

void MainMenuScene::showWindow()
{

	this->newGameButton->showButton();
	this->endGameButton->showButton();
	al_flip_display();
}

