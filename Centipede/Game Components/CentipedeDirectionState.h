#ifndef CENTI_DIRECTION_STATE_H
#define CENTI_DIRECTION_STATE_H

#include "MovementCollection.h"

class CentipedeHead;

class CentipedeDirectionState
{
	///states dont need to have a constructor because none of them store any information
public:
	virtual ~CentipedeDirectionState() = default;

	virtual const CentipedeDirectionState* NextState(CentipedeHead * centi) const { return nullptr; }

	virtual OffsetArray GetOffsetArray() const { return {0, 0}; }

	/**
	 * \brief this will be called by the centipede, and will use the parameters depending on the class
	 * \param centi 
	 * \param counter: used just for horz moving states, only cares about checking ahead
	 * \param yCounter: used just for vert moving states, just to know when to turn back to horz
	 */
	virtual void CheckAhead(CentipedeHead *centi, unsigned int &counter, unsigned int &yCounter) const {}
};

#endif //CENTI_DIRECTION_STATE_H