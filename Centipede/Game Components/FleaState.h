#ifndef FLEA_STATE
#define FLEA_STATE

#include "State.h"

class Flea;

class FleaState : public State
{
public:
	FleaState() {};
	virtual ~FleaState() {};
	FleaState &operator=(const FleaState &c) = delete;
	FleaState(const FleaState &c) = delete;

	virtual void TakeDamage() = 0;
	virtual void StateAction() = 0;

private:

};

#endif //FLEA_STATE