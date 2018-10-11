#ifndef CENTIMOVEMENT_H
#define CENTIMOVEMENT_H

//one include for all the movements
#include "CentipedeDirectionState.h"
#include "CentipedeHead.h"
#include "GameGrid.h"


#include "MoveFSM.h"
#include "Centi_UpThenRight.h"
#include "Centi_UpThenLeft.h"
#include "Centi_DownThenLeft.h"
#include "Centi_DownThenRight.h"
#include "Centi_LeftThenDown.h"
#include "Centi_LeftThenUp.h"
#include "Centi_RightThenUp.h"
#include "Centi_RightThenDown.h"

#include "Body_Left.h"
#include "Body_Down.h"
#include "Body_Right.h"
#include "Body_Up.h"

#define CENTI_SPEED 2
#define WORKING false

#endif // !CENTIMOVEMENT_H
