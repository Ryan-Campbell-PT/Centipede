#ifndef UP_THENRIGHT_H
#define UP_THENRIGHT_H

#include "SpiderMovementState.h"

class Up_ThenRight : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
public:
	
};

#endif // UP_THENRIGHT_H
