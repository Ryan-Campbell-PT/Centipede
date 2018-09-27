#ifndef RIGHT_SPIDER_STATE
#define RIGHT_SPIDER_STATE

#include "SpiderStates.h"

class Spider;

class RightSpiderState : public HorzSpiderState
{
	RightSpiderState(Spider *spider);
	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //RIGHT_SPIDER_STATE