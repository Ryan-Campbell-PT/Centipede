#pragma once
#include "SpiderMovementState.h"

class Spider_DiagonalDownLeft :  ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual ImprovedSpiderState* GetNextState() const override;
public:
	
};
