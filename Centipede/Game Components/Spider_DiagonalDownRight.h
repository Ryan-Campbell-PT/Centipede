﻿#ifndef SPIDER_DIAGONALDOWNRIGHT_H
#define SPIDER_DIAGONALDOWNRIGHT_H

#include "SpiderMovementState.h"

class Spider_DiagonalDownRight : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
	virtual const ImprovedSpiderState* GetExtraState() const override;
};

#endif // SPIDER_DIAGONALDOWNRIGHT_H
