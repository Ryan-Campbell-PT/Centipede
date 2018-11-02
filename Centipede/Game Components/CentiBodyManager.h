#ifndef CENTIBODY_MANAGER
#define CENTIBODY_MANAGER

//#include <list>
//using std::list;
#include "TEAL/CommonElements.h"
#include "MovementCollection.h"

class CentipedeBody;
enum class CentiMovementDirectionEnum;
class CentipedeDirectionState;
class CentipedePart;

class CentiBodyManager
{
public:
	static CentipedeBody* GetCentiBody();
	static CentipedeBody* GetInitializedCentiBody(sf::Vector2f const &pos, OffsetArray const &direction);

	///in this one, we will assume we are given the body that has been removed, but not the head that will become body
	///this one also assumes we have been shot
	static void SetBehindBodyToHead(CentipedeBody *body);
	///this one assumes whatever head is given to us, is the body that will become the head
	static void SetBodyToHead(CentipedeBody *body);

	CentiBodyManager(const CentiBodyManager &s) = delete;
	CentiBodyManager operator = (const CentiBodyManager &) = delete;
	static void EndWave();

	static void Terminate();

private:
	CentiBodyManager() = default;
	virtual ~CentiBodyManager() = default;

	void AlignLinks(CentipedePart * leader, CentipedePart* follower);

	///if a body is destroyed, but doesnt know what direction to do, we will search for the head
	///then get that direction
	const CentipedeDirectionState * GetBodysHeadDirection(CentipedeBody *body);

	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
};



#endif // !CENTIBODY_MANAGER
