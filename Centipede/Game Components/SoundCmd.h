#ifndef SOUNDCMD_H
#define SOUNDCMD_H
#include <SFML/Audio/Sound.hpp>
#include "SoundManager.h"

class SoundCmd
{
protected:
	sf::Sound sound;

public:
	explicit SoundCmd(const sf::Sound &sound)
		:sound(sound)
	{
		this->sound.setVolume(10);
	}

	virtual void Execute()
	{
		SoundManager::PlaySound(this->sound);
	}

	virtual ~SoundCmd() = default;
};
#endif // SOUNDCMD_H
