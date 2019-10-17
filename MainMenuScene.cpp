#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(int screenWidth, int screenHeight, const char* gameTitle,Stage * stage)
	:Scene(screenWidth, screenHeight, gameTitle),stage(stage)
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
	al_draw_bitmap(this->background, 0, 0, 0);
	int x = 0, y = 0;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		if (events.type == ALLEGRO_EVENT_TIMER) {

			if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) {
				this->done = true;
			}
		}

		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->newGameButton->buttonClick(x, y)) {
					cout << "START NEW GAME" << endl;
					this->stage->showGame();
				}
				if (this->endGameButton->buttonClick(x, y)) {
					break;
				}
			}

		}

		this->newGameButton->showButton();
		this->endGameButton->showButton();
		al_flip_display();

	}


	
}

