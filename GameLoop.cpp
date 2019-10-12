#include "GameLoop.h"

GameLoop::GameLoop(Window *newWindow)
{
	try {
		if (newWindow == NULL)
			throw "Window has not been initialized";
		this->window = newWindow;
		this->timer = al_create_timer(1.0 / FPS);
		this->event_queue = al_create_event_queue();
	}
	catch (string ex) {
		cout << ex << endl;
	}
	
}

GameLoop::~GameLoop()
{
	delete this->window;

	al_destroy_timer(this ->timer);
	al_destroy_event_queue(this->event_queue);
}

void GameLoop::startLoop()
{

	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());


	al_start_timer(this->timer);
	while (!this->done){
		

		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);
		

		if (events.type == ALLEGRO_EVENT_TIMER) {

			if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) {
				this->done = true;
			}
		}				 

		window->showWindow();	
	}


}
