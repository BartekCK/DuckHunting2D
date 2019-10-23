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


	this->soundEffect = al_load_sample(path.MUSIC_SHOT);
	this->song = al_load_sample(path.MUSIC_GAME);
	al_reserve_samples(2);

	this->songInstance = al_create_sample_instance(this->song);
	al_set_sample_instance_playmode(this->songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(this->songInstance, al_get_default_mixer());
}

GameScene::~GameScene()
{
	for (int i = 0; i < COUNT_DUCKS; i++) {
		delete this->duck[i];
	}
	for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
		delete this->groundDuck[i];
	}

	al_destroy_sample(soundEffect);
	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	Text text;
	this->gameTime = 15;
	al_play_sample_instance(songInstance);
	registerEvent();
	startTimers();

	done = false;
	bool move = true;
	float x = 0, y = 0;
	Hunter *hunter = new Hunter(this->display);
	

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


				al_play_sample(soundEffect, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				
			}

		}
		
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			cout << "Hunter points " << hunter->getPoints() << endl;
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

	if (gameTime == 0) {
		text.gameEndInformation(this->display, hunter->getPoints());
	}

	stopTimers();
	delete hunter;
	deleteEvent();
	this->stage->showMenu();
	
}
