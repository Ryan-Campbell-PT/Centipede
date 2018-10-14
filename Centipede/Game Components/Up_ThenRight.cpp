#include "Up_ThenRight.h"
#include "Spider_MoveFSM.h"

OffsetArray Up_ThenRight::GetOffsetArray() const
{
	return Spider_MovementCollection::Up_ThenRight;
}

ImprovedSpiderState* Up_ThenRight::GetNextState() const
{
	return &Spider_MoveFSM::down_ThenRight;
}
