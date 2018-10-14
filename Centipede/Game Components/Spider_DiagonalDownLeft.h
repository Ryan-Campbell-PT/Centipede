#ifndef SPIDER_DIAGONALDOWNLEFT_H
#define SPIDER_DIAGONALDOWNLEFT_H

#include "SpiderMovementState.h"

class Spider_DiagonalDownLeft : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
};

#endif // SPIDER_DIAGONALDOWNLEFT_H
