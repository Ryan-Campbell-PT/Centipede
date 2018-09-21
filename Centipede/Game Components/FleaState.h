#ifndef FLEA_STATE
#define FLEA_STATE

#include "State.h"

class FleaState : public State
{
public:
	FleaState() {};
	virtual ~FleaState() {};
	FleaState &operator=(const FleaState &c) = delete;
	FleaState(const FleaState &c) = delete;

private:

};

#endif //FLEA_STATE