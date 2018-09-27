#ifndef VERTICAL_SPIDER_STATE
#define VERTICAL_SPIDER_STATE

#include "SpiderStates.h"

class Spider;

///this class is for when the spider is going directly up and down
///i created my classes poorly
class BouncingSpiderState : public VerticalSpiderState
{
	BouncingSpiderState(Spider *spider, HorzSpiderState *prevHorz, VerticalSpiderState *prevVert);

	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //VERTICAL_SPIDER_STATE