#ifndef CENTIRIGHT_H
#define CENTIRIGHT_H

#include "CentipedeDirectionState.h"

class CentiMoveRight : public CentipedeDirectionState
{
public:
	CentiMoveRight(CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveRight() override;
private:
	CentipedeHead * centipede;
};


#endif //CENTIRIGHT_H