#ifndef MOVE_FSM
#define MOVE_FSM


#include "CentiMovement.h"
#include "CentipedeDirectionState.h"

class Centi_RightThenUp;
class Centi_RightThenDown;
class Centi_UpThenRight;
class Centi_UpThenLeft;
class Centi_DownThenRight;
class Centi_DownThenLeft;
class Centi_LeftThenDown;
class Centi_LeftThenUp;
class Centi_Poisoned;
class Centi_PoisonedThenLeft;
class Centi_PoisonedThenRight;

struct MoveSFM
{
	static const Centi_RightThenUp			rightThenUp;
	static const Centi_RightThenDown		rightThenDown;
	static const Centi_UpThenRight			upThenRight;
	static const Centi_UpThenLeft			upThenLeft;
	static const Centi_DownThenRight		downThenRight;
	static const Centi_DownThenLeft			downThenLeft;
	static const Centi_LeftThenDown			leftThenDown;
	static const Centi_LeftThenUp			leftThenUp;
	static const Centi_PoisonedThenLeft		poisonedThenLeft;
	static const Centi_PoisonedThenRight	poisonedThenRight;
};

#endif // !MOVE_FSM
