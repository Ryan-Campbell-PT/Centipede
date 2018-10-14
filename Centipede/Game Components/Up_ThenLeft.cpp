﻿#include "SpiderStates.h"


OffsetArray Up_ThenLeft::GetOffsetArray() const
{
	return Spider_MovementCollection::Down_ThenLeft;
}

const ImprovedSpiderState* Up_ThenLeft::GetNextState() const
{
	return &Spider_MoveFSM::down_ThenLeft;
}