#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "TEAL/CommonElements.h"
#include <queue>
#include "TEAL/ResourceManager.h"

class SoundCmd;

class SoundManager
{
public:
	enum class SoundEvent
	{
		ScorpionSpawn,
		FleaSpawn,
		SpiderSpawn,
		ShipFire,
		Death,
		Beat,

	};

	static void PlaySound(sf::Sound sound);
	static SoundCmd *GetSound(SoundEvent event);

	static void ProcessSounds();

private:
	//these have to be non-static because initialzing them in class creates an error
	const sf::Sound scorpSpawn = sf::Sound(ResourceManager::GetSound("Scorpion"));
	const sf::Sound fleaSpawn = sf::Sound(ResourceManager::GetSound("Flea"));
	const sf::Sound spiderSpawn = sf::Sound(ResourceManager::GetSound("Spider"));
	const sf::Sound shipFire = sf::Sound(ResourceManager::GetSound("Fire1"));
	const sf::Sound death = sf::Sound(ResourceManager::GetSound("Death"));
	const sf::Sound beat = sf::Sound(ResourceManager::GetSound("Beat"));
	
	SoundManager()
	{
		//todo: seems like cheating. find a better way
		//const_cast<sf::Sound*>(&scorpSpawn)->setBuffer();
		//scorpSpawn = sf::Sound()
	}

	std::queue<SoundCmd*> soundQueue;
};
#endif // SOUNDMANAGER_H
