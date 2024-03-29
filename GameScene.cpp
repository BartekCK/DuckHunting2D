#include "GameScene.h"

GameScene::GameScene(Stage* stage)
	: stage(stage)
{
	Path path;


	for (int i = 0; i < COUNT_DUCKS; i++) {
		Duck *duck = new Duck(path.NODE_DUCK, 20, 2);
		duckList.push_back(duck);
	}
	for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
		GroundDuck *groundDuck = new GroundDuck(path.GROUND_DUCK, 16, 2);
		duckList.push_back(groundDuck);

	}
	for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
		SuperDuck *superDuck = new SuperDuck(path.SUPER_DUCK, 14, 2);
		duckList.push_back(superDuck);
	}

	

}

GameScene::~GameScene()
{
	for (size_t  i = 0; i < duckList.size(); i++) {
		delete duckList[i];
	}
	

	cout << "DESTRUKTOR Z GAME_SCENE" << endl;
}

void GameScene::showWindow()
{
	Text text;
	Music* music = new Music();
	music->playMusic();
	tempGameTime = gameTime;
	done = false;
	bool move = true;
	float x = 0, y = 0;
	Hunter *hunter = new Hunter(engine->returnDisplay());
	Hunter::points = 0;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_TIMER) {

			for (size_t  i = 0; i < duckList.size(); i++) {
				duckList[i]->move(events);
			}
			
			if (events.timer.source == engine->timmerVector[3]) {

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
				

				for (size_t  i = 0; i < duckList.size(); i++) {
					if (duckList[i]->checkShoot(x, y)) {
						hunter->addPoints(duckList[i]->getPoint());
						music->shotSound();
					}
				}
			
				
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
			for (size_t  i = 0; i < duckList.size(); i++) {
				duckList[i]->show();
			}
			hunter->getCross()->showCross(x, y);

			text.showTime(gameTime);
			text.showPoint(hunter->getPoints(),screen_width);

			al_flip_display();
		}
				
	}

	delete hunter;
	delete music;
	this->stage->showRanking();
	
}







