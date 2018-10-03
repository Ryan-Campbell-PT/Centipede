#ifndef CENTI_DIRECTION_STATE_H
#define CENTI_DIRECTION_STATE_H

#include "State.h"
#include "TEAL/CommonElements.h"

class CentipedeHead;

enum class CentiMovementDirectionEnum;

class CentipedeDirectionState : public State
{
public:
	///each state will do one thing and thats move in the direction specified. The centipede handles when to change it
	virtual void MoveDirection(sf::Vector2f &pos) {};
	///this method will have the class itself determine what direction the centipede should be going after it no longer can go in that direction
	virtual const CentipedeDirectionState* NextState()  {};
	///because we arent able to return the actual instance of the CentiDirection, we return an enum instead
	virtual CentiMovementDirectionEnum GetDirectionEnum() {};

	virtual void Initialize(CentipedeHead *centi) {};
	//virtual void Initialize(CentipedeHead *centi, sf::Vector2f &pos) {};

protected:
	///removing destructor because linker doesnt like it
	//virtual ~CentipedeDirectionState() = 0; 
	CentipedeDirectionState() {};

private:
	//CentipedeDirectionState &operator=(const CentipedeDirectionState &c) = delete;
	//CentipedeDirectionState(const CentipedeDirectionState &c) = delete;
};

#endif //CENTI_DIRECTION_STATE_H