#include "Down_ThenLeft.h"
#include "Spider_MoveFSM.h"

OffsetArray Down_ThenLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenLeft;
}

ImprovedSpiderState* Down_ThenLeft::GetNextState() const
{
	return &Spider_MoveFSM::up_ThenLeft;
}
