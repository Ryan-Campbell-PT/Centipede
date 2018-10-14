#ifndef DOWN_THENRIGHT_H
#define DOWN_THENRIGHT_H

#include "SpiderMovementState.h"

class Down_ThenRight : public ImprovedSpiderState
{
public:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
};

#endif // DOWN_THENRIGHT_H
