#pragma once
#include "SpiderMovementState.h"

class Down_ThenRight : ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual ImprovedSpiderState* GetNextState() const override;
public:
	
};
