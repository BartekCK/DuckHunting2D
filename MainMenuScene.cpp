#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle,Stage * stage)
	:Scene(screenWidth, screenHeight, gameTitle),stage(stage)
{
	Path path;
	this->newGameButton = new Button(path.BUTTON_NEW_GAME);
	this->endGameButton = new Button(path.BUTTON_END_GAME);

	this->newGameButton->setXposition((this->screen_width / 2) - (this->newGameButton->getBitmapWidth()/2));
	this->newGameButton->setYposition((this->screen_height / 2) -(this->newGameButton->getBitmapHeight() / 2)-100);

	this->endGameButton->setXposition((this->screen_width / 2) - (this->endGameButton->getBitmapWidth() / 2));
	this->endGameButton->setYposition((this->screen_height / 2) - (this->endGameButton->getBitmapHeight() / 2)+100);
	
}

MainMenuScene::~MainMenuScene()
{
	delete newGameButton;
	delete endGameButton;
	cout << "DESKTRUKTOR Z MAIN_MENU_SCENE" << endl;
}

void MainMenuScene::showWindow()
{
	int x = 0, y = 0;
	bool test = false;
	registerEvent();

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		
		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->newGameButton->buttonClick(x, y)) {
					cout << "START NEW GAME" << endl;
					test = true;
					break;
					
				}
				if (this->endGameButton->buttonClick(x, y)) {
					break;
				}
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);

		this->newGameButton->show();
		this->endGameButton->show();
		al_flip_display();
	}
	
	deleteEvent();
	if (test == true) {
		this->stage->showTimers();

	}
}

