#include "Music.h"

Music::Music()
{
	Path path;
	this->soundEffect = al_load_sample(path.MUSIC_SHOT);
	this->song = al_load_sample(path.MUSIC_GAME);
	al_reserve_samples(2);

	this->songInstance = al_create_sample_instance(this->song);
	al_set_sample_instance_playmode(this->songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(this->songInstance, al_get_default_mixer());
}

Music::~Music()
{
	al_destroy_sample(soundEffect);
	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
}

void Music::shotSound()
{
	al_play_sample(soundEffect, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

}

void Music::playMusic()
{
	al_play_sample_instance(songInstance);
}
