
#include "SpiderMovementState.h"

class Spider_DiagonalUpLeft : ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual ImprovedSpiderState* GetNextState() const override;	
};
