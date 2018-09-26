#ifndef OBSERVEE_H
#define OBSERVEE_H

#include "TEAL/CommonElements.h"

class Observer
{
public:
	virtual void ObserverUpdate(int numShrooms) = 0;

private:

};

#endif //OBSERVEE_H