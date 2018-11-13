#ifndef SPIDER_STATE
#define SPIDER_STATE

#include "MovementCollection.h"

class ImprovedSpiderState
{
public:
	virtual ~ImprovedSpiderState() = default;
	virtual OffsetArray GetOffsetArray() const = 0;
	virtual const ImprovedSpiderState* GetNextState() const = 0;
	virtual const ImprovedSpiderState* GetExtraState() const = 0;
};

#endif