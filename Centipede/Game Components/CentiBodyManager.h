#ifndef CENTIBODY_MANAGER
#define CENTIBODY_MANAGER

//#include <list>
//using std::list;
#include "TEAL/CommonElements.h"

class CentipedeBody;
enum class CentiMovementDirectionEnum;

class CentiBodyManager
{
public:
	static CentipedeBody* GetCentiBody();
	static CentipedeBody* GetInitializedCentiBody(sf::Vector2f const &pos, CentiMovementDirectionEnum const &direction);

private:
	CentiBodyManager() {};
	
	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIBODY_MANAGER
