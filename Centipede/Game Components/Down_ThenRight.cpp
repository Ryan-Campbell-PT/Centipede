#include "Down_ThenRight.h"
#include "Spider_MoveFSM.h"

OffsetArray Down_ThenRight::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenRight;
}

ImprovedSpiderState* Down_ThenRight::GetNextState() const
{
	return &Spider_MoveFSM::up_ThenRight
}
