#include "Spider_DiagonalUpLeft.h"
#include "Spider_MoveFSM.h"

OffsetArray Spider_DiagonalUpLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalUpLeft;
}

ImprovedSpiderState* Spider_DiagonalUpLeft::GetNextState() const
{
	return &Spider_MoveFSM::diagonalDownLeft;
}
