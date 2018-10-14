#include "SpiderStates.h"


OffsetArray Spider_DiagonalUpLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalUpLeft;
}

const ImprovedSpiderState* Spider_DiagonalUpLeft::GetNextState() const
{
	return &Spider_MoveFSM::diagonalDownLeft;
}

const ImprovedSpiderState * Spider_DiagonalUpLeft::GetExtraState() const
{
	return &Spider_MoveFSM::down_ThenLeft;
}
