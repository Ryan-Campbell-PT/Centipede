#ifndef CENTIUP_H
#define CENTIUP_H

#include "CentipedeDirectionState.h"


class CentiMoveUp : public CentipedeDirectionState
{
public:
	CentiMoveUp(CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveUp() override;
private:
	CentipedeHead * centipede;
};


#endif //CENTIup_H