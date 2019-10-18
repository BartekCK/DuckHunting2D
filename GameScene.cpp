#include "GameScene.h"
#include "math.h"

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	duck = new Duck(path.NODE_DUCK,20,2);
}

GameScene::~GameScene()
{
	delete duck;
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	
	registerEvent();
	al_start_timer(this -> timer);
	done = false;
	bool move = true;


	//DO KLASY DUCK !!!
	
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {



			
			duck->move(this->screen_width, this->screen_height);

		



			
			move = true;
		}

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
		}

		else if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
			
		}




		if (move == true) {
			move = false;
			al_draw_bitmap(this->background, 0, 0, 0);
			duck->show();

			al_flip_display();
		}
		
	}


	al_stop_timer(this->timer);
	deleteEvent();
	this->stage->showMenu();
}
