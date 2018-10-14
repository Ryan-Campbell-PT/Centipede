#pragma once
#include "SpiderMovementState.h"

class Spider_DiagonalDownRight : ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual ImprovedSpiderState* GetNextState() const override;	
};
