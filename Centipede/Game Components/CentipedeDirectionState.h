#ifndef CENTI_DIRECTION_STATE_H
#define CENTI_DIRECTION_STATE_H

#include "State.h"

class CentipedeHead;

class CentipedeDirectionState : public State
{
public:
	///each state will do one thing and thats move in the direction specified. The centipede handles when to change it
	virtual void MoveDirection() = 0;
	///this method will have the class itself determine what direction the centipede should be going after it no longer can go in that direction
	virtual void NextState() = 0;

private:
	CentipedeDirectionState();
	virtual ~CentipedeDirectionState() {};
	CentipedeDirectionState &operator=(const CentipedeDirectionState &c) = delete;
	CentipedeDirectionState(const CentipedeDirectionState &c) = delete;
};

class CentiMoveLeft : public CentipedeDirectionState
{
	CentiMoveLeft(const CentipedeHead *centi);

	virtual void MoveDirection() override;
};

class CentiMoveRight : public CentipedeDirectionState
{
	CentiMoveRight(const CentipedeHead *centi);

	virtual void MoveDirection() override;
};

class CentiMoveDown : public CentipedeDirectionState
{
	CentiMoveDown(const CentipedeHead *centi);

	virtual void MoveDirection() override;
};

class CentiMoveUp : public CentipedeDirectionState
{
	CentiMoveUp(const CentipedeHead *centi);

	virtual void MoveDirection() override;
};


#endif //CENTI_DIRECTION_STATE_H