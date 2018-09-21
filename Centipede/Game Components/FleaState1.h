#ifndef FLEASTATE_1
#define FLEASTATE_1

#include "TEAL/CommonElements.h"
#include "FleaState.h"

class FleaState1 : public FleaState
{
public:
	FleaState1();
	virtual ~FleaState1();
	FleaState1 &operator=(const FleaState1 &c) = delete;
	FleaState1(const FleaState1 &c) = delete;

private:

};

#endif //FLEASTATE_1