#include "SpiderStates.h"

OffsetArray Up_ThenRight::GetOffsetArray() const
{
	return Spider_MovementCollection::Up_ThenRight;
}

const ImprovedSpiderState* Up_ThenRight::GetNextState() const
{
	return &Spider_MoveFSM::down_ThenRight;
}

const ImprovedSpiderState * Up_ThenRight::GetExtraState() const
{
	return &Spider_MoveFSM::diagonalDownRight;
}
