#include "SpiderMovement.h"


OffsetArray Up_ThenLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::Up_ThenLeft;
}

const ImprovedSpiderState* Up_ThenLeft::GetNextState() const
{
	return &Spider_MoveFSM::down_ThenLeft;
}

const ImprovedSpiderState * Up_ThenLeft::GetExtraState() const
{
	return &Spider_MoveFSM::diagonalDownLeft;
}
