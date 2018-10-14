#include "SpiderStates.h"

OffsetArray Spider_DiagonalUpRight::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalUpRight;
}

const ImprovedSpiderState* Spider_DiagonalUpRight::GetNextState() const
{
	return &Spider_MoveFSM::diagonalDownRight;
}
