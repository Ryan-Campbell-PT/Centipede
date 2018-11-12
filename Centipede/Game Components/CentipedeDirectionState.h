#ifndef CENTI_DIRECTION_STATE_H
#define CENTI_DIRECTION_STATE_H

#include "State.h"
#include "TEAL/CommonElements.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"

class CentipedeHead;

enum class CentiMovementDirectionEnum;

class CentipedeDirectionState
{
public:
	virtual ~CentipedeDirectionState() = default;

	///each state will do one thing and thats move in the direction specified. The centipede handles when to change it
	virtual void MoveDirection(CentipedeHead *centi, sf::Vector2f &pos) const {}
	///this method will have the class itself determine what direction the centipede should be going after it no longer can go in that direction
	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const { return nullptr; }
	///because we arent able to return the actual instance of the CentiDirection, we return an enum instead
	virtual CentiMovementDirectionEnum GetDirectionEnum() const { return CentiMovementDirectionEnum::Error; }

	virtual void Initialize(CentipedeHead *centi) const {}
	
	virtual OffsetArray GetOffsetArray() const { return {0, 0}; }

	virtual void CheckAhead(CentipedeHead *centi, unsigned int &counter, unsigned int &yCounter) const {}

protected:
	CentipedeDirectionState() = default;
};

#endif //CENTI_DIRECTION_STATE_H