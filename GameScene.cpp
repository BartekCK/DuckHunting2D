#include "GameScene.h"
#include "math.h"

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	duck = new Duck(path.NODE_DUCK,40,2);
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
	bool orientationX = true, orientationY = true;
	bool animation = false;
	enum direction { LEFT, RIGHT };
	int x = 0, y = 0;
	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {



			if (duck->getXposition() == 0) {
				orientationX = true;
				duck->shiftY = duck->getHeight() / 2;
			}
			else if (duck->getXposition() == screen_width) {
				orientationX = false;
				duck->shiftY = 0;
				
			}
			if (orientationX)
				x += duck->moveSpeed;
			else
				x -= duck->moveSpeed;
			
			
			if (orientationY)
				y += duck->moveSpeed;
			else
				y -= duck->moveSpeed;
			if (y == 0)
				orientationY = true;
			if (y == screen_height/4)
				orientationY = false;

			
			
			//if (animation) {
				duck->shiftX += ((duck->getWidth() / duck->frames));

				if (duck->shiftX > duck->getWidth())
					duck->shiftX = 0;
			//}
			




			duck->setXposition(x);
			duck->setYposition(y);
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
