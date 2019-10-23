#include "GameScene.h"
#include <sstream>

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	for (int i = 0; i < COUNT_DUCKS; i++) {
		this->duck[i] = new Duck(path.NODE_DUCK, 20, 2);
	}
	for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
		this->groundDuck[i] = new GroundDuck(path.GROUND_DUCK, 16, 2);
	}
	for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
		this->superDuck[i] = new SuperDuck(path.SUPER_DUCK, 14, 2);
	}



}

GameScene::~GameScene()
{
	for (int i = 0; i < COUNT_DUCKS; i++) {
		delete this->duck[i];
	}
	for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
		delete this->groundDuck[i];
	}


	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	displayRegister();
	Text text;
	registerEvent();
	startTimers();
	Music* music = new Music();
	music->playMusic();

	done = false;
	bool move = true;
	float x = 0, y = 0;
	Hunter *hunter = new Hunter(this->display);
	Hunter::points = 0;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			if (events.timer.source == timer[0]) {
				for (int i = 0; i < COUNT_DUCKS; i++) {
					this->duck[i]->move();
				}
			}
			if (events.timer.source == timer[1]) {
				
				for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
					this->groundDuck[i]->move();
				}
			}
			if (events.timer.source == timer[2]) {
				
				for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
					this->superDuck[i]->move();
				}
			}
			if (events.timer.source == timer[3]) {

				gameTime--;
				if (gameTime == 0) {
					break;
				}
			}
			


			
			move = true;
		}
		if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = events.mouse.x;
			y = events.mouse.y;
			
		}
		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {//SHOT
				x = events.mouse.x;
				y = events.mouse.y;
				
				for (int i = 0; i < COUNT_DUCKS; i++) {
					
					if (duck[i]->checkShoot(x, y, i))
						hunter->addPoints(duck[i]->getPoint());

				}


				for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
					if (groundDuck[i]->checkShoot(x, y, i))
						hunter->addPoints(groundDuck[i]->getPoint());
				}
				for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
					if (superDuck[i]->checkShoot(x, y, i))
						hunter->addPoints(superDuck[i]->getPoint());
				}

				music->shotSound();
				
			}

		}
		
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
		}
		

		if (move == true) {//ALL SHOW
			move = false;
			al_draw_bitmap(this->background, 0, 0, 0);
			for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
				this->groundDuck[i]->show();
			}
			for (int i = 0; i < COUNT_DUCKS; i++) {
				this->duck[i]->show();
			}
			for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
				this->superDuck[i]->show();
			}
			hunter->getCross()->showCross(x, y);


			text.showTime(gameTime);
			text.showPoint(hunter->getPoints(),screen_width);

			al_flip_display();
		}
				
	}

	/*if (gameTime == 0) {
		text.gameEndInformation(this->display, hunter->getPoints());
	}*/

	stopTimers();
	delete hunter;
	delete music;
	deleteEvent();
	displayDelete();
	this->stage->showRanking();
	
}
