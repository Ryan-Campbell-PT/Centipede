#ifndef UP_SPIDER_STATE
#define UP_SPIDER_STATE

#include "SpiderStates.h"

class Spider;

class UpSpiderState : public VerticalSpiderState
{
	UpSpiderState(Spider *spider);
	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //UP_SPIDER_STATE