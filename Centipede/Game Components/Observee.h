#ifndef OBSERVER_H
#define OBSERVER_H

#include "TEAL/CommonElements.h"

class Observer;

class Observee
{
public:
	virtual void AddObservee(Observer *o) = 0;
	virtual void RemoveObservee(Observer *o) = 0;

protected:
	virtual void UpdateObservees() = 0;

private:

};

#endif //OBSERVER_H