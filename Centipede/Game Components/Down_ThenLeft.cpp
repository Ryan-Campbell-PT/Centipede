#include "SpiderStates.h"


OffsetArray Down_ThenLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenLeft;
}

const ImprovedSpiderState* Down_ThenLeft::GetNextState() const
{
	return &Spider_MoveFSM::up_ThenLeft;
}
