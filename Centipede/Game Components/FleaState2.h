#ifndef FLEASTATE_2
#define FLEASTATE_2

#include "TEAL/CommonElements.h"
#include "FleaState.h"

class FleaState2 : public FleaState
{
public:
	FleaState2(Flea *flea)
		:flea(flea) {};
	virtual ~FleaState2() {};
	FleaState2 &operator=(const FleaState2 &c) = delete;
	FleaState2(const FleaState2 &c) = delete;

	virtual void TakeDamage() override
	{
		this->flea->RemoveFlea();
	}

	///b/c its in its second state, the flea doesnt do anyting but go fast
	virtual void StateAction() override {}

private:
	Flea * flea;
};

#endif //FLEASTATE_2