#ifndef DOWN_THENLEFT_H
#define DOWN_THENLEFT_H

#include "SpiderMovementState.h"

class Down_ThenLeft : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
public:
	
};

#endif // DOWN_THENLEFT_H
