#ifndef CENTIBODY_POOL
#define CENTIBODY_POOL

#include <list>

class CentipedeBody;
class GameObject;

class CentiBodyPool
{
public:
	static CentipedeBody * GetCentiBody();
	static void RecycleCentiBody(GameObject * const body);

	CentiBodyPool(const CentiBodyPool &pool) = delete;
	CentiBodyPool operator = (const CentiBodyPool &pool) = delete;
	
	static void Terminate();

private:
	CentiBodyPool() = default;
	~CentiBodyPool() = default;


	static CentiBodyPool* GetInstance();

	static CentiBodyPool* instance;
	std::list<CentipedeBody*> inactiveBodyList;
	std::list<CentipedeBody*> activeBodyList;
};



#endif // !CENTIBODY_POOL
