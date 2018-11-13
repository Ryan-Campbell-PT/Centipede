#ifndef SPIDER_DIAGONALUPRIGHT_H
#define SPIDER_DIAGONALUPRIGHT_H

#include "SpiderMovement.h"

class Spider_DiagonalUpRight : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;	
	virtual const ImprovedSpiderState* GetExtraState() const override;
};

#endif // SPIDER_DIAGONALUPRIGHT_H
