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
	virtual void processSounds() override;

	virtual void sendSoundCommand(SoundCmd* cmd) override;

	std::queue<SoundCmd*> soundQueue;
};

inline void SoundOn::processSounds()
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

inline void SoundOn::sendSoundCommand(SoundCmd* cmd)
{
#if testing
		this->soundQueue.push(cmd);
#endif
}

#endif // SOUNDON_H
