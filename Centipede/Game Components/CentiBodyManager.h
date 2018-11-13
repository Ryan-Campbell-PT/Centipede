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
	static CentipedeBody* GetInitializedCentiBody(sf::Vector2f const &pos, const int &speed, OffsetArray const &direction);

	
	static void SetBodyToHead(CentipedeBody *body, const CentipedeDirectionState * direction);

	/**
	 * \brief this function differs than the one above because it assumes we dont know the direction
	 * so it is used by bodies in the middle of the centipede
	 * \param body 
	 */
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
	const CentipedeDirectionState * GetBodysHeadDirection(CentipedeBody *body) const;

	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
};



#endif // !CENTIBODY_MANAGER
