#ifndef FLEASTATE_1
#define FLEASTATE_1

#include "TEAL/CommonElements.h"
#include "FleaState.h"
#include "FleaState2.h"
#include "GameGrid.h"

class FleaState1 : public FleaState
{
public:
	FleaState1() = default;

	virtual ~FleaState1() = default;
	FleaState1 &operator=(const FleaState1 &c) = delete;
	FleaState1(const FleaState1 &c) = delete;

	virtual void TakeDamage(Flea *flea) override
	{
		flea->SetSpeed(FLEASTATE2);
		flea->SetState(new FleaState2);
	}

	virtual void StateAction(Flea *flea) override
	{
		if (static_cast<int>(flea->GetPosition().y) % SPRITE_SIZE == 0)
		{
			//this spawning method is very ineffecient atm, will fix later
			if (rand() % 3 == 0)
				flea->AttemptSpawnMushroom();
		}
	}

private:
};

#endif //FLEASTATE_1