#ifndef CENTILEFT_H
#define CENTILEFT_H

#include "CentipedeDirectionState.h"

class CentiMoveLeft : public CentipedeDirectionState
{
public:
	CentiMoveLeft(CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveLeft() override;
private:
	CentipedeHead * centipede;
};

#endif //CENTILEFT_H