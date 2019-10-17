#include "GameScene.h"

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
}

GameScene::~GameScene()
{
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	al_draw_bitmap(this->background, 0, 0, 0);
	bool test = false;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
	

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					test = true;
			}
		}

		
		if (test == true) {
			test = false;
			this->stage->showMenu();
			break;
		}

		al_flip_display();
	}


	
}
