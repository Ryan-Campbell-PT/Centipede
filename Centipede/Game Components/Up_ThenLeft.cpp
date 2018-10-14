#include "Up_ThenLeft.h"
#include "Spider_MoveFSM.h"

OffsetArray Up_ThenLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenLeft;
}

ImprovedSpiderState* Up_ThenLeft::GetNextState() const
{
	return &Spider_MoveFSM::down_ThenLeft;
}
