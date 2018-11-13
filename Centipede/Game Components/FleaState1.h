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

	virtual void TakeDamage(Flea *flea) override;

	virtual void StateAction(Flea *flea) override;

private:
	int shroomSpawn = 3;
};

inline void FleaState1::TakeDamage(Flea* flea)
{
	flea->SetSpeed(FLEASTATE2);
	flea->SetState(Flea::FleaStateEnum::State2);
}

inline void FleaState1::StateAction(Flea* flea)
{
	if (static_cast<int>(flea->GetPosition().y) % SPRITE_SIZE == 0)
	{
		if (rand() % shroomSpawn == 0)
			flea->AttemptSpawnMushroom();
	}
}


#endif //FLEASTATE_1