#ifndef SOUNDON_H
#define SOUNDON_H

#include "SoundManager.h"
#include "SoundCmd.h"

#define testing true
class SoundOn : public SoundManager
{
public:
	SoundOn() = default;

private:
	virtual void processSounds() override
	{
#if testing
		SoundCmd *sound = nullptr;
		while (!this->soundQueue.empty())
		{
			sound = this->soundQueue.front();
			this->soundQueue.pop();

			sound->Execute();
		}
#endif
	}

	virtual void sendSoundCommand(SoundCmd* cmd) override
	{
#if testing
		this->soundQueue.push(cmd);
#endif
	}

private:
	std::queue<SoundCmd*> soundQueue;
};
#endif // SOUNDON_H
