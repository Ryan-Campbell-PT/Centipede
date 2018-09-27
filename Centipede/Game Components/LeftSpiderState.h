#ifndef LEFT_SPIDER_STATE
#define LEFT_SPIDER_STATE

#include "SpiderStates.h"

class Spider;

class LeftSpiderState : public HorzSpiderState
{
	LeftSpiderState(Spider *spider);
	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //LEFT_SPIDER_STATE