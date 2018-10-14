#include "SpiderStates.h"


OffsetArray Spider_DiagonalDownLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalDownLeft;
}

const ImprovedSpiderState* Spider_DiagonalDownLeft::GetNextState() const
{
	return &Spider_MoveFSM::diagonalUpLeft;
}
