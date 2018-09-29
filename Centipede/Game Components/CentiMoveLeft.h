#ifndef CENTILEFT_H
#define CENTILEFT_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveLeft : public CentipedeDirectionState
{
public:
	CentiMoveLeft(CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
	//virtual ~CentiMoveLeft() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
};

#endif //CENTILEFT_H