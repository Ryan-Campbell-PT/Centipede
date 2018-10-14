#ifndef VERTICAL_SPIDER_STATE_LEFT
#define VERTICAL_SPIDER_STATE_LEFT

#include "SpiderStates.h"

class Spider;

///this class is for when the spider is going directly up and down
///i created my classes poorly
class BouncingSpiderStateLeft : public VerticalSpiderState
{
	BouncingSpiderStateLeft(Spider *spider, HorzSpiderState *prevHorz, VerticalSpiderState *prevVert);

	virtual void GetNextState() override;
	virtual void MoveDirection(sf::Vector2f &pos) override;

};

#endif //VERTICAL_SPIDER_STATE_LEFT