#include "GameScene.h"
#include "math.h"

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	for (int i = 0; i < COUNT_DUCKS; i++) {
		this->duck[i] = new Duck(path.NODE_DUCK, 20, 2);
	}
}

GameScene::~GameScene()
{
	for (int i = 0; i < COUNT_DUCKS; i++) {
		delete this->duck[i];
	}
	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	registerEvent();
	al_start_timer(this -> timer);
	done = false;
	bool move = true;
	float x = 0, y = 0;
	Crosshair *cross = new Crosshair(this->display);

	//DO KLASY DUCK !!!
	
	
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {



			for (int i = 0; i < COUNT_DUCKS; i++) {
				this->duck[i]->move();
			}


			
			move = true;
		}
		if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = events.mouse.x;
			y = events.mouse.y;
			
		}
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
			}
		}
		

		if (move == true) {
			move = false;
			al_draw_bitmap(this->background, 0, 0, 0);
			for (int i = 0; i < COUNT_DUCKS; i++) {
				this->duck[i]->show();
			}
			cross->showCross(x, y);
			al_flip_display();
		}
		
		
		
	}

	al_stop_timer(this->timer);
	delete cross;
	deleteEvent();
	this->stage->showMenu();
}
