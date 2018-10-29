#ifndef CENTIHEAD_POOL
#define CENTIHEAD_POOL

#include <list>

class CentipedeHead;
class GameObject;

class CentiHeadPool
{
public:
	static CentipedeHead * GetCentiHead();
	static void RecycleCentiBody(GameObject * const body);

	CentiHeadPool(const CentiHeadPool &pool) = delete;
	CentiHeadPool operator = (const CentiHeadPool &pool) = delete;
	static void EndWave();

private:
	CentiHeadPool() = default;
	~CentiHeadPool();


	static CentiHeadPool* GetInstance();

	static CentiHeadPool* instance;
	std::list<CentipedeHead*> headList;
	int numActiveCenti;
};



#endif // !CENTIBODY_POOL
