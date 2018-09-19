#include "CentipedeDirectionState.h"
#include "CentipedeHead.h"

CentiMoveLeft::CentiMoveLeft(const CentipedeHead * centi)
{
	this->centipede = const_cast<CentipedeHead *>(centi);
}

void CentiMoveLeft::MoveDirection(sf::Vector2f &pos)
{
	pos.x -= 3;

	if (pos.x < 12)
		this->centipede->currentDirectionState = new CentiMoveDown(this->centipede);
}

void CentiMoveLeft::NextState()
{
}

//CentiMoveLeft::~CentiMoveLeft()
//{
//}

CentiMoveRight::CentiMoveRight(const CentipedeHead * centi)
{
}

void CentiMoveRight::MoveDirection(sf::Vector2f &pos)
{
}

void CentiMoveRight::NextState()
{
}

//CentiMoveRight::~CentiMoveRight()
//{
//}

CentiMoveDown::CentiMoveDown(const CentipedeHead * centi)
{
	this->centipede = const_cast<CentipedeHead *>(centi);
}

void CentiMoveDown::MoveDirection(sf::Vector2f &pos)
{
	pos.y += 3;
}

void CentiMoveDown::NextState()
{
}

//CentiMoveDown::~CentiMoveDown()
//{
//}

CentiMoveUp::CentiMoveUp(const CentipedeHead * centi)
{
}

void CentiMoveUp::MoveDirection(sf::Vector2f &pos)
{
}

void CentiMoveUp::NextState()
{
}

//CentiMoveUp::~CentiMoveUp()
//{
//}
