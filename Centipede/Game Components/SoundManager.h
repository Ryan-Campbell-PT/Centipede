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
		SpiderLoop,
		ShipFire,
		Death,
		Beat,

	};

	static void PlaySound(sf::Sound &sound);
	static SoundCmd *GetSound(SoundEvent even);
	static void SendSoundCommand(SoundCmd *cmd);
	static void ProcessSounds();
	static void SetSoundProfile(SoundManager *profile);
	static void Terminate();

protected:
	SoundManager(); //protected to allow children to be created
	virtual void processSounds() {}
	virtual void sendSoundCommand(SoundCmd *cmd) {}

private:
	//these have to be non-static because initialzing them in class creates an error
	const sf::Sound scorpSpawn = sf::Sound(ResourceManager::GetSound("Scorpion"));
	const sf::Sound fleaSpawn = sf::Sound(ResourceManager::GetSound("Flea"));
	const sf::Sound spiderSpawn = sf::Sound(ResourceManager::GetSound("Spider"));
	const sf::Sound spiderLoop = sf::Sound(ResourceManager::GetSound("SpiderLoop"));
	const sf::Sound shipFire = sf::Sound(ResourceManager::GetSound("Fire1"));
	const sf::Sound death = sf::Sound(ResourceManager::GetSound("Death"));
	const sf::Sound beat = sf::Sound(ResourceManager::GetSound("Beat"));

	static SoundManager* GetInstance();

	static SoundManager* instance;
	SoundManager* soundProfile;
};
#endif // SOUNDMANAGER_H
