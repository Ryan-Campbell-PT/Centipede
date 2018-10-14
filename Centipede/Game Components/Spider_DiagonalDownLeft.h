#ifndef SPIDER_DIAGONALDOWNLEFT_H
#define SPIDER_DIAGONALDOWNLEFT_H

#include "SpiderMovementState.h"

class Spider_DiagonalDownLeft : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
public:
	
};

#endif // SPIDER_DIAGONALDOWNLEFT_H
