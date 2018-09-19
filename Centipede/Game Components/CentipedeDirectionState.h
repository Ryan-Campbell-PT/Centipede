#ifndef CENTI_DIRECTION_STATE_H
#define CENTI_DIRECTION_STATE_H

#include "State.h"
#include "TEAL/CommonElements.h"

class CentipedeHead;

class CentipedeDirectionState : public State
{
public:
	///each state will do one thing and thats move in the direction specified. The centipede handles when to change it
	virtual void MoveDirection(sf::Vector2f &pos) = 0;
	///this method will have the class itself determine what direction the centipede should be going after it no longer can go in that direction
	virtual void NextState() = 0;

protected:
	///removing destructor because linker doesnt like it
	//virtual ~CentipedeDirectionState() = 0; 
	CentipedeDirectionState() {};

private:
	CentipedeDirectionState &operator=(const CentipedeDirectionState &c) = delete;
	CentipedeDirectionState(const CentipedeDirectionState &c) = delete;
};

class CentiMoveLeft : public CentipedeDirectionState
{
public:
	CentiMoveLeft(const CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveLeft() override;
private:
	CentipedeHead * centipede;
};

class CentiMoveRight : public CentipedeDirectionState
{
public:
	CentiMoveRight(const CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveRight() override;
private:
	CentipedeHead * centipede;
};

class CentiMoveDown : public CentipedeDirectionState
{
public:
	CentiMoveDown(const CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveDown() override;
private:
	CentipedeHead * centipede;
};

class CentiMoveUp : public CentipedeDirectionState
{
public:
	CentiMoveUp(const CentipedeHead *centi);

	virtual void MoveDirection(sf::Vector2f &pos) override;
	virtual void NextState() override;

	//virtual ~CentiMoveUp() override;
private:
	CentipedeHead * centipede;
};


#endif //CENTI_DIRECTION_STATE_H