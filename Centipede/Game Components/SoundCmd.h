#ifndef SOUNDCMD_H
#define SOUNDCMD_H
#include <SFML/Audio/Sound.hpp>
#include "SoundManager.h"

class SoundCmd
{
protected:
	sf::Sound sound;

public:
	virtual void Execute()
	{
		SoundManager::PlaySound(this->sound);
	}
};
#endif // SOUNDCMD_H
