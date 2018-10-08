#ifndef CENTIBODY_POOL
#define CENTIBODY_POOL

#include <list>
using std::list;

class CentipedeBody;

class CentiBodyPool
{
public:
	CentipedeBody * GetCentiBody() const;
	void RecycleCentiBody(CentipedeBody * const body) const;

private:
	CentiBodyPool() {};

	static CentiBodyPool* GetInstance();

	static CentiBodyPool* instance;
	std::list<CentipedeBody*> bodyList;
};



#endif // !CENTIBODY_POOL
