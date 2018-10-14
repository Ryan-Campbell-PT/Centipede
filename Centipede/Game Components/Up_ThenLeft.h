#ifndef UP_THENLEFT_H
#define UP_THENLEFT_H

#include "SpiderMovementState.h"

class Up_ThenLeft : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
	virtual const ImprovedSpiderState* GetExtraState() const override;
};

#endif // UP_THENLEFT_H
