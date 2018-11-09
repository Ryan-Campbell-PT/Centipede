#ifndef CENTIHEAD_POOL
#define CENTIHEAD_POOL

#include <list>

class CentipedeHead;
class GameObject;

class CentiHeadPool
{
public:
	static CentipedeHead * GetCentiHead();
	static void RecycleCentiHead(GameObject * const body);

	CentiHeadPool(const CentiHeadPool &pool) = delete;
	CentiHeadPool operator = (const CentiHeadPool &pool) = delete;
	static void EndWave();

	static void Terminate();

private:
	CentiHeadPool() 
	:numActiveCenti(0), frame(0) {}
	~CentiHeadPool() = default;


	static CentiHeadPool* GetInstance();

	static CentiHeadPool* instance;
	std::list<CentipedeHead*> inactiveHeadList;
	std::list<CentipedeHead*> activeHeadList;
	int numActiveCenti;
	float frame;
};



#endif // !CENTIBODY_POOL
