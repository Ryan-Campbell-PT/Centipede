#ifndef OBSERVER_H
#define OBSERVER_H

#include "TEAL/CommonElements.h"

class Observee;

class Observer
{
public:
	virtual void AddObservee(Observee *o) = 0;
	virtual void RemoveObservee(Observee *o) = 0;

protected:
	virtual void UpdateObservees() = 0;

private:

};

#endif //OBSERVER_H