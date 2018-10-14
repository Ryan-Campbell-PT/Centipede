﻿#ifndef SPIDER_DIAGONALUPRIGHT_H
#define SPIDER_DIAGONALUPRIGHT_H

#include "SpiderStates.h"

class Spider_DiagonalUpRight : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;	
};

#endif // SPIDER_DIAGONALUPRIGHT_H
