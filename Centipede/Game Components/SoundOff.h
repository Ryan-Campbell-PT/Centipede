#ifndef SOUNDOFF_H
#define SOUNDOFF_H

#include "SoundManager.h"

class SoundOff : public SoundManager
{
public:
	SoundOff() = default;

private:
	virtual void processSounds() override {}
	virtual void sendSoundCommand(SoundCmd* cmd) override {}
};
#endif // SOUNDOFF_H
