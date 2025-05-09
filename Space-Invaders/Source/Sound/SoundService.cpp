#include "Sound/SoundService.h"
#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
		loadExplosionSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
			printf("error loading BG music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("error loading button click sound");
	}

	void SoundService::loadExplosionSoundFromFile()
	{
		if (!buffer_explosion.loadFromFile(Config::explosion_sound_path))
			printf("error loading explosion sound");
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;

		case SoundType::EXPLOSION:
			sound_effect.setBuffer(buffer_explosion);
			break;

		default:
			printf("invalid Sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}


}