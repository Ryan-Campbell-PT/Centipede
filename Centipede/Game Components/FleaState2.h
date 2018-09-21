#ifndef FLEASTATE_1
#define FLEASTATE_1

#include "TEAL/CommonElements.h"
#include "FleaState.h"

class FleaState2 : public FleaState
{
public:
	FleaState2();
	virtual ~FleaState2();
	FleaState2 &operator=(const FleaState2 &c) = delete;
	FleaState2(const FleaState2 &c) = delete;

private:

};

#endif //FLEASTATE_1