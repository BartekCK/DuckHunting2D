#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle)
	:Scene(screenWidth, screenHeight, gameTitle)
{
	this->newGameButton = new Button("images/buttons/buttonNewGame.png");
	this->endGameButton = new Button("images/buttons/buttonEndGame.png");

	newGameButton->setButtonImage();
	endGameButton->setButtonImage();

	newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getButtonWidth()/2));
	newGameButton->setYposition((this->screen_height / 2) -(this->newGameButton->getButtonHeight() / 2)-100);

	endGameButton->setXposition((this->screen_width / 2) - (this->endGameButton->getButtonWidth() / 2));
	endGameButton->setYposition((this->screen_height / 2) - (this->endGameButton->getButtonHeight() / 2)+100);
	
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
