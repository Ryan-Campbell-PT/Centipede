#ifndef CENTIRIGHT_H
#define CENTIRIGHT_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveRight : public CentipedeDirectionState
{
public:
	CentiMoveRight();

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;
	///my choice to add the position to the Initialize is to center it in the grid as the centipede starts moving
	void Initialize(CentipedeHead *centi, sf::Vector2f &pos);

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
	//virtual ~CentiMoveRight() override;
private:
	virtual void Initialize(CentipedeHead *centi) override;
	
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
};


#endif //CENTIRIGHT_H