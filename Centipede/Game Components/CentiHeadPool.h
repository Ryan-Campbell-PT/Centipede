#ifndef CENTIHEAD_POOL
#define CENTIHEAD_POOL

#include <list>
using std::list;

class CentipedeHead;

class CentiHeadPool
{
public:
	static CentipedeHead * GetCentiHead();
	static void RecycleCentiBody(CentipedeHead * const body);

private:
	CentiHeadPool() {};

	static CentiHeadPool* GetInstance();

	static CentiHeadPool* instance;
	std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIBODY_POOL
