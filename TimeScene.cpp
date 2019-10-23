#include "TimeScene.h"

TimeScene::TimeScene(int screenWidth, int screenHeight, const char* gameTitle, Stage* stage)
	:Scene(screenWidth, screenHeight, gameTitle), stage(stage)
{
	Path path;
	this->button = new Button(path.BUTTON_15_S);

	
	int buttonX = (this->screen_width / 2) - (this->button->getBitmapWidth() / 2);
	int buttonY = (this->screen_height / 2) - (this->button->getBitmapHeight() / 2);
	this->button->setXposition(buttonX);
	this->button->setYposition(buttonY);

	
}

TimeScene::~TimeScene()
{
	delete button;
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
				if (this->button->buttonClick(x, y)) {
					cout << "START NEW GAME" << endl;
					break;

				}
				
			}

		}


		al_draw_bitmap(this->background, 0, 0, 0);
		this->button->show();
		al_flip_display();
	}

	deleteEvent();
	this->stage->showGame();
}
