#include "SoundManager.h"
#include "SoundCmd.h"

SoundManager *SoundManager::instance = nullptr;

SoundManager::SoundManager()
	: soundProfile(nullptr)
{
}

void SoundManager::PlaySound(sf::Sound &sound)
{
	sound.play();
}

SoundCmd * SoundManager::GetSound(SoundEvent even)
{
	SoundCmd * cmd = nullptr;

	switch (even)
	{
	case SoundEvent::ScorpionSpawn:
		cmd = new SoundCmd(GetInstance()->scorpSpawn);
		break;
	case SoundEvent::FleaSpawn:
		cmd = new SoundCmd(GetInstance()->fleaSpawn);
		break;
	case SoundEvent::SpiderSpawn:
		cmd = new SoundCmd(GetInstance()->spiderSpawn);
		break;
	case SoundEvent::SpiderLoop:
		cmd = new SoundCmd(GetInstance()->spiderLoop);
		break;
	case SoundEvent::ShipFire:
		cmd = new SoundCmd(GetInstance()->shipFire);
		break;
	case SoundEvent::Death:
		cmd = new SoundCmd(GetInstance()->death);
		break;
	case SoundEvent::Beat:
		cmd = new SoundCmd(GetInstance()->beat);
		break;
	default:
		break;
	}

	return cmd;
}

void SoundManager::SendSoundCommand(SoundCmd * cmd)
{
	GetInstance()->soundProfile->sendSoundCommand(cmd);
}

void SoundManager::ProcessSounds()
{
	GetInstance()->soundProfile->processSounds();
}

void SoundManager::SetSoundProfile(SoundManager * profile)
{
	delete GetInstance()->soundProfile;
	instance->soundProfile = profile;
}

SoundManager * SoundManager::GetInstance()
{
	if (instance == nullptr)
		instance = new SoundManager;

	return instance;
}