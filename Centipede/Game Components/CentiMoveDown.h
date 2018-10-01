#ifndef CENTIDOWN_H
#define CENTIDOWN_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveDown : public CentipedeDirectionState
{
public:
	CentiMoveDown();

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;
	virtual void Initialize(CentipedeHead *centi) override;

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
	int counter;
};


#endif //CENTIdown_H