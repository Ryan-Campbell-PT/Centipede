#ifndef CENTIRIGHT_H
#define CENTIRIGHT_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveRight : public CentipedeDirectionState
{
public:
	///my choice to add the position to the constructor is to center it in the grid as the centipede starts moving
	CentiMoveRight(CentipedeHead *centi, sf::Vector2f &pos);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
	//virtual ~CentiMoveRight() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
};


#endif //CENTIRIGHT_H