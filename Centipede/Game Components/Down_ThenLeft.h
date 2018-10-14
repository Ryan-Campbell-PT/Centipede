#ifndef DOWN_THENLEFT_H
#define DOWN_THENLEFT_H

#include "SpiderMovementState.h"

class Down_ThenLeft : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;	
	virtual const ImprovedSpiderState* GetExtraState() const override;
};

#endif // DOWN_THENLEFT_H
