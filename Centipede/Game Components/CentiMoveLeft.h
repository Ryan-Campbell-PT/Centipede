#ifndef CENTILEFT_H
#define CENTILEFT_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveLeft : public CentipedeDirectionState
{
public:
	///my choice to add the position to the constructor is to center it in the grid as the centipede starts moving
	CentiMoveLeft(CentipedeHead *centi, sf::Vector2f &pos);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
	//virtual ~CentiMoveLeft() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
};

#endif //CENTILEFT_H