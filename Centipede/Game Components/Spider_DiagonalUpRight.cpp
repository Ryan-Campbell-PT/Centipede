#include "Spider_DiagonalUpRight.h"
#include "Spider_MoveFSM.h"

OffsetArray Spider_DiagonalUpRight::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalUpRight;
}

ImprovedSpiderState* Spider_DiagonalUpRight::GetNextState() const
{
	return &Spider_MoveFSM::diagonalDownRight;
}
