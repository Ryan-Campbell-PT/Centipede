#ifndef UP_THENLEFT_H
#define UP_THENLEFT_H

#include "SpiderMovementState.h"

class Up_ThenLeft : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
public:
	
};

#endif // UP_THENLEFT_H
