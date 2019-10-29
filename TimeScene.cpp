#include "TimeScene.h"

TimeScene::TimeScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	this->button[0] = new Button(path.BUTTON_15_S);
	this->button[1] = new Button(path.BUTTON_30_S);
	this->button[2] = new Button(path.BUTTON_60_S);

	
	int buttonX = (this->screen_width / 2) - (this->button[0]->getBitmapWidth() / 2);
	int h = 0;
	int buttonY = 0;
	for (int i = 0; i < 3; i++) {
		buttonY = (this->screen_height / 3) - (this->button[0]->getBitmapHeight() / 2) + h;
		this->button[i]->setXposition(buttonX);
		this->button[i]->setYposition(buttonY);
		h += 150;
	}


	
}

TimeScene::~TimeScene()
{
	for (int i = 0; i < 3; i++) {
		delete button[i];
	}
}

void TimeScene::showWindow()
{
	int x = 0, y = 0;
	registerEvent();

	while (!this->done) {

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (events.mouse.button & 1) {
				x = events.mouse.x;
				y = events.mouse.y;
				if (this->button[0]->buttonClick(x, y)) {
					gameTime = 15;
					break;

				}
				if (this->button[1]->buttonClick(x, y)) {
					gameTime = 30;
					break;

				}
				if (this->button[2]->buttonClick(x, y)) {
					gameTime = 60;
					break;

				}

			}

		}


		al_draw_bitmap(this->background, 0, 0, 0);
		for (int i = 0; i < 3; i++) {
			this->button[i]->show();
		}
		al_flip_display();
	}

	deleteEvent();

	this->stage->showGame();
}
