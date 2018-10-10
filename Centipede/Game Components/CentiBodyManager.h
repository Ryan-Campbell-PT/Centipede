#ifndef CENTIBODY_MANAGER
#define CENTIBODY_MANAGER

//#include <list>
//using std::list;
#include "TEAL/CommonElements.h"

class CentipedeBody;
enum class CentiMovementDirectionEnum;
class CentipedeDirectionState;
class CentipedePart;

class CentiBodyManager
{
public:
	static CentipedeBody* GetCentiBody();
	static CentipedeBody* GetInitializedCentiBody(sf::Vector2f const &pos, CentiMovementDirectionEnum const &direction);
	static void MakeBodyHead(CentipedeBody *body); ///this will be used if the body is being destroyed from the middle of the centi
	static void MakeBodyHead(CentipedeBody * body, const CentipedeDirectionState *direction); ///this can be used if the head is being destroyed

	static void RemoveCentiBody(CentipedeBody *body, const bool &makeBehindHead, const bool &spawnShroom = true);

	//static void FromHeadToBody(CentipedeBody *body); ///this function handles from turning a body
	//static void FromBodyToHead(CentipedeBody *body);
private:
	CentiBodyManager() = default;

	void AlignLinks(CentipedePart * leader, CentipedePart* follower);

	///if a body is destroyed, but doesnt know what direction to do, we will search for the head
	///then get that direction
	const CentipedeDirectionState * GetBodysHeadDirection(CentipedeBody *body);

	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIBODY_MANAGER
