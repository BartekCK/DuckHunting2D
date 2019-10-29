#include "RankingScene.h"
#include "Text.h"
#include "Loader.h"
#include "Hunter.h"

RankingScene::RankingScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	this->button = new Button(path.BUTTON_NEW_GAME);
	button->setXposition((this->screen_width / 2) - (this->button->getBitmapWidth() / 2));
	button->setYposition((this->screen_height) - (this->button->getBitmapHeight())-100);
}

RankingScene::~RankingScene()
{
	delete button;
}





void RankingScene::showWindow()
{
	checkPoints();

	int x = 0, y = 0;

	Text text;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(engine->event_queue, &events);


		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->button->buttonClick(x, y)) {
					break;

				}
				
			}

		}
		al_draw_bitmap(this->background, 0, 0, 0);
		this->button->show();

		text.showPoint(Hunter::points, screen_width / 2, 50);
		text.bestRanking15(bestPoints[0],screen_width/2,300);
		text.bestRanking30(bestPoints[1],screen_width/2,450);
		text.bestRanking60(bestPoints[2],screen_width/2,600);
		al_flip_display();
	}
	tempGameTime = 0;
	
	this->stage->showMenu();
	
}

void RankingScene::checkPoints()
{
	Loader loader;
	loader.readFromFile(bestPoints);

	int value = 0;
	int i = 0;
	if (tempGameTime == 15)
	{
		i = 0;
		istringstream iss(bestPoints[i]);
		iss >> value;

	}
	else if (tempGameTime == 30)
	{
		i = 1;
		istringstream iss(bestPoints[i]);
		iss >> value;

	}
	else
	{
		i = 2;
		istringstream iss(bestPoints[i]);
		iss >> value;

	}

	if (Hunter::points > value) {
		ostringstream ss;
		ss << Hunter::points;
		bestPoints[i] = ss.str();
		loader.saveToFile(bestPoints);
	}
}
