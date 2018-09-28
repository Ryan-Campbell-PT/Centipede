#ifndef CENTIDOWN_H
#define CENTIDOWN_H

#include "CentipedeDirectionState.h"

class CentiMoveDown : public CentipedeDirectionState
{
public:
	CentiMoveDown(CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveDown() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
};


#endif //CENTIdown_H