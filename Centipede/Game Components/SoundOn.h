#ifndef SOUNDON_H
#define SOUNDON_H

#include "SoundManager.h"
#include "SoundCmd.h"

class SoundOn : public SoundManager
{
public:
	SoundOn() = default;

private:
	virtual void processSounds() override
	{
		SoundCmd *sound = nullptr;
		while (!this->soundQueue.empty())
		{
			sound = this->soundQueue.front();
			this->soundQueue.pop();

			sound->Execute();
		}
	}

	virtual void sendSoundCommand(SoundCmd* cmd) override
	{
		this->soundQueue.push(cmd);
	}

private:
	std::queue<SoundCmd*> soundQueue;
};
#endif // SOUNDON_H
