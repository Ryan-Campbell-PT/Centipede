#ifndef SPIDER_DIAGONALDOWNRIGHT_H
#define SPIDER_DIAGONALDOWNRIGHT_H

#include "SpiderMovementState.h"

class Spider_DiagonalDownRight : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;	
};

#endif // SPIDER_DIAGONALDOWNRIGHT_H
