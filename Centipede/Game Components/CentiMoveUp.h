#ifndef CENTIUP_H
#define CENTIUP_H

#include "CentipedeDirectionState.h"

enum class CentiMovementDirectionEnum;

class CentiMoveUp : public CentipedeDirectionState
{
public:
	CentiMoveUp();

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;
	virtual void Initialize(CentipedeHead *centi) override;

	virtual CentiMovementDirectionEnum GetDirectionEnum() override;
	//virtual ~CentiMoveUp() override;
private:
	CentipedeHead * centipede;
	CentiMovementDirectionEnum prevState;
	int counter;
};


#endif //CENTIUP_H