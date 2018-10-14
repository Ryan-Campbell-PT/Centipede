#include "Spider_DiagonalDownLeft.h"
#include "Spider_MoveFSM.h"

OffsetArray Spider_DiagonalDownLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalDownLeft;
}

ImprovedSpiderState* Spider_DiagonalDownLeft::GetNextState() const
{
	return &Spider_MoveFSM::diagonalUpLeft;
}
