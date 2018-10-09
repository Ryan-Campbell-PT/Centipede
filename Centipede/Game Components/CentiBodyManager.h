#ifndef CENTIBODY_MANAGER
#define CENTIBODY_MANAGER

//#include <list>
//using std::list;
#include "TEAL/CommonElements.h"

class CentipedeBody;
enum class CentiMovementDirectionEnum;
class CentipedeDirectionState;

class CentiBodyManager
{
public:
	static CentipedeBody* GetCentiBody();
	static CentipedeBody* GetInitializedCentiBody(sf::Vector2f const &pos, CentiMovementDirectionEnum const &direction);
	static void MakeBodyHead(CentipedeBody *body); ///this will be used if the body is being destroyed from the middle of the centi
	static void MakeBodyHead(CentipedeBody * body, CentipedeDirectionState *direction); ///this can be used if the head is being destroyed

private:
	CentiBodyManager() {};
	
	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIBODY_MANAGER
