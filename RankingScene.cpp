#include "RankingScene.h"
#include "Text.h"
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
	displayRegister();
	int x = 0, y = 0;
	registerEvent();

	Text text;

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);


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

		text.showPoint(Hunter::points, screen_width / 2, 0);
		text.bestRanking15(screen_width/2,300);
		text.bestRanking30(screen_width/2,450);
		text.bestRanking60(screen_width/2,600);
		al_flip_display();
	}

	deleteEvent();
	displayDelete();
	this->stage->showMenu();
	
}
