#include "SpiderStates.h"


OffsetArray Spider_DiagonalDownRight::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalDownRight;
}

const ImprovedSpiderState* Spider_DiagonalDownRight::GetNextState() const
{
	return &Spider_MoveFSM::diagonalUpRight;
}

const ImprovedSpiderState * Spider_DiagonalDownRight::GetExtraState() const
{
	return &Spider_MoveFSM::up_ThenRight;
}
