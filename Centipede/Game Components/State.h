#ifndef STATE_H
#define STATE_H

//this will be the interface all classes that use the State Pattern will use
class State
{
public:
	virtual ~State();
	virtual void changeState(State *state) final; //I want to keep this so children cant override it
	
private:
	State * currentState;
};

#endif //STATE_H