#include "SoundManager.h"
#include "SoundCmd.h"
#include "SoundOn.h"
#include "SoundOff.h"

SoundManager *SoundManager::instance = nullptr;

SoundManager::SoundManager()
	: soundProfile(nullptr), soundOn(nullptr), soundOff(nullptr)
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

void SoundManager::SetSoundProfile(SoundStatus status)
{
	if (status == SoundStatus::On)
	{
		if (GetInstance()->soundOn == nullptr)
			instance->soundOn = new SoundOn;
		instance->soundProfile = instance->soundOn;
	}
	else
	{
		if (GetInstance()->soundOff == nullptr)
			instance->soundOff = new SoundOff;
		GetInstance()->soundProfile = instance->soundOff;
	}
}

void SoundManager::Terminate()
{
	delete GetInstance()->soundOff;
	delete instance->soundOn;
	instance->soundOff = nullptr;
	instance->soundOn = nullptr;
	delete instance;
	instance = nullptr;

}

SoundManager * SoundManager::GetInstance()
{
	if (instance == nullptr)
		instance = new SoundManager;

	return instance;
}
