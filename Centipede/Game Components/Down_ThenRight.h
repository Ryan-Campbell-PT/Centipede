#ifndef DOWN_THENRIGHT_H
#define DOWN_THENRIGHT_H

#include "SpiderMovementState.h"

class Down_ThenRight : public ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const override;
	virtual const ImprovedSpiderState* GetNextState() const override;
public:
	
};

#endif // DOWN_THENRIGHT_H
