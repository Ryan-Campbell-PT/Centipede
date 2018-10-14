#pragma once
#include "SpiderMovementState.h"

class Up_ThenRight : ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual ImprovedSpiderState* GetNextState() const override;
public:
	
};
