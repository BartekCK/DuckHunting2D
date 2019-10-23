#pragma once
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Path.h"
class Music
{
	ALLEGRO_SAMPLE* soundEffect = NULL;
	ALLEGRO_SAMPLE* song = NULL;
	ALLEGRO_SAMPLE_INSTANCE* songInstance = NULL;
public:
	Music();
	~Music();

	void shotSound();
	void playMusic();
};

