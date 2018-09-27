#ifndef DOWN_SPIDER_STATE
#define DOWN_SPIDER_STATE

#include "SpiderStates.h"

class Spider;

class DownSpiderState : public VerticalSpiderState
{
	DownSpiderState(Spider *spider);
	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //DOWN_SPIDER_STATE