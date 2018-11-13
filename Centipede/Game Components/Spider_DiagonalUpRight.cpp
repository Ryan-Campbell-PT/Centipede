#include "SpiderMovement.h"

OffsetArray Spider_DiagonalUpRight::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalUpRight;
}

const ImprovedSpiderState* Spider_DiagonalUpRight::GetNextState() const
{
	return &Spider_MoveFSM::diagonalDownRight;
}

const ImprovedSpiderState * Spider_DiagonalUpRight::GetExtraState() const
{
	return &Spider_MoveFSM::down_ThenRight;
}
