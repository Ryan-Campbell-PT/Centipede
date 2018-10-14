#ifndef SPIDER_DIAGONALUPLEFT_H
#define SPIDER_DIAGONALUPLEFT_H

#include "SpiderMovementState.h"

class Spider_DiagonalUpLeft : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;	
};

#endif // SPIDER_DIAGONALUPLEFT_H
