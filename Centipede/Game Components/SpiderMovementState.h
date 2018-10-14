#ifndef SPIDER_STATE
#define SPIDER_STATE

#include "TEAL/CommonElements.h"
#include "State.h"
#include "MovementCollection.h"

class SpiderMovementState : public State
{
	virtual void GetNextState() = 0;
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
};

class VerticalSpiderState : public SpiderMovementState
{
	virtual void GetNextState() = 0;
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
};

class HorzSpiderState : public SpiderMovementState
{
	virtual void GetNextState() = 0;
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
};

class ImprovedSpiderState
{
protected:
	virtual OffsetArray GetOffsetArray() const { return Spider_MovementCollection::DiagonalDownLeft; }
	virtual ImprovedSpiderState* GetNextState() const { return nullptr; }
};

#endif