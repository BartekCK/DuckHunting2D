#include "GameScene.h"
#include <sstream>

GameScene::GameScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;


	for (int i = 0; i < COUNT_DUCKS; i++) {
		Duck *duck = new Duck(path.NODE_DUCK, 20, 2);
		duckList.push_front(duck);
	}
	for (int i = 0; i < COUNT__GROUND_DUCKS; i++) {
		GroundDuck *groundDuck = new GroundDuck(path.GROUND_DUCK, 16, 2);
		groundDuckList.push_front(groundDuck);

	}
	for (int i = 0; i < COUNT_SUPER_DUCKS; i++) {
		SuperDuck *superDuck = new SuperDuck(path.SUPER_DUCK, 14, 2);
		superDuckList.push_front(superDuck);
	}

	

}

GameScene::~GameScene()
{
	for (itd = duckList.begin(); itd != duckList.end(); ++itd) {
		delete (*itd);
	}
	for (itg = groundDuckList.begin(); itg != groundDuckList.end(); ++itg) {
		delete (*itg);
	}
	for (its = superDuckList.begin(); its != superDuckList.end(); ++its) {
		delete (*its);
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

			if (events.timer.source == engine->timmerVector[0]) {
				for (itd = duckList.begin(); itd != duckList.end(); ++itd) {
					(*itd)->move();
				}
			}
			if (events.timer.source == engine->timmerVector[1]) {
				
				for (itg = groundDuckList.begin(); itg != groundDuckList.end(); ++itg) {
					(*itg)->move();
				}
			}
			if (events.timer.source == engine->timmerVector[2]) {
				
				for (its = superDuckList.begin(); its != superDuckList.end(); ++its) {
					(*its)->move();
				}
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
				
				for (itd = duckList.begin(); itd != duckList.end(); ++itd) {
					if((*itd)->checkShoot(x, y, 0))
						hunter->addPoints((*itd)->getPoint());
				}
				for (itg = groundDuckList.begin(); itg != groundDuckList.end(); ++itg) {
					if ((*itg)->checkShoot(x, y, 0))
						hunter->addPoints((*itg)->getPoint());
				}
				for (its = superDuckList.begin(); its != superDuckList.end(); ++its) {
					if ((*its)->checkShoot(x, y, 0))
						hunter->addPoints((*its)->getPoint());
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
			for (itd = duckList.begin(); itd != duckList.end(); ++itd) {
				(*itd)->show();
			}
			for (itg = groundDuckList.begin(); itg != groundDuckList.end(); ++itg) {
				(*itg)->show();
			}
			for (its = superDuckList.begin(); its != superDuckList.end(); ++its) {
				(*its)->show();
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







