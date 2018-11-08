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

	static void Terminate();
	static void SetBS(bool bs) {GetInstance()->bs = bs;}

private:
	CentiHeadPool() 
	:numActiveCenti(0), bs(false) {}
	~CentiHeadPool() = default;


	static CentiHeadPool* GetInstance();

	static CentiHeadPool* instance;
	std::list<CentipedeHead*> inactiveHeadList;
	std::list<CentipedeHead*> activeHeadList;
	int numActiveCenti;
	bool bs; //todo fix this
};



#endif // !CENTIBODY_POOL
