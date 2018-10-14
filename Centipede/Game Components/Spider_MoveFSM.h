#ifndef SPIDER_MOVE_FSM
#define SPIDER_MOVE_FSM


class Spider_DiagonalDownLeft;
class Spider_DiagonalDownRight;
class Spider_DiagonalUpLeft;
class Spider_DiagonalUpRight;
class Down_ThenLeft;
class Down_ThenRight;
class Up_ThenLeft;
class Up_ThenRight;

struct Spider_MoveFSM
{
	static const Spider_DiagonalDownLeft diagonalDownLeft;
	static const Spider_DiagonalDownRight diagonalDownRight;
	static const Spider_DiagonalUpLeft diagonalUpLeft;
	static const Spider_DiagonalUpRight diagonalUpRight;
	static const Down_ThenLeft down_ThenLeft;
	static const Down_ThenRight down_ThenRight;
	static const Up_ThenLeft up_ThenLeft;
	static const Up_ThenRight up_ThenRight;
	
};

#endif //SPIDER_MOVE_FSM