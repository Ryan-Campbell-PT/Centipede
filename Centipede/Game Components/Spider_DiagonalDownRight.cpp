#include "Spider_DiagonalDownRight.h"
#include "Spider_MoveFSM.h"

OffsetArray Spider_DiagonalDownRight::GetOffsetArray() const
{
	return Spider_MovementCollection::DiagonalDownRight;
}

ImprovedSpiderState* Spider_DiagonalDownRight::GetNextState() const
{
	return &Spider_MoveFSM::diagonalUpRight;
}
