#include "SpiderStates.h"


OffsetArray Down_ThenRight::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenRight;
}

const ImprovedSpiderState* Down_ThenRight::GetNextState() const
{
	return &Spider_MoveFSM::up_ThenRight;
}

const ImprovedSpiderState * Down_ThenRight::GetExtraState() const
{
	return &Spider_MoveFSM::diagonalUpRight;
}
