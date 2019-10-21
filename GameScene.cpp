#include "GameScene.h"

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

	soundEffect = al_load_sample(path.MUSIC_SHOT);
	al_reserve_samples(1);
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
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	registerEvent();
	al_start_timer(this -> timer);
	done = false;
	bool move = true;
	float x = 0, y = 0;
	Hunter *hunter = new Hunter(this->display);
	
	int duckWidth = duck[0]->getBitmapWidth()/20;
	int duckHeight = duck[0]->getBitmapHeight()/2;
	


	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {



			for (int i = 0; i < COUNT_DUCKS; i++) {
				this->duck[i]->move();
			}
			for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
				this->groundDuck[i]->move();
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
						hunter->addPoints(Duck::point);
					
				}


				for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
					if (groundDuck[i]->checkShoot(x, y, i))
						hunter->addPoints(Duck::point);
				}
				al_play_sample(soundEffect, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
				
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
			hunter->getCross()->showCross(x, y);
			al_flip_display();
		}
		
		
		
	}

	al_stop_timer(this->timer);
	delete hunter;
	deleteEvent();
	this->stage->showMenu();
}
