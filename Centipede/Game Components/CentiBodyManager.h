#ifndef CENTIBODY_MANAGER
#define CENTIBODY_MANAGER

//#include <list>
//using std::list;

class CentipedeBody;

class CentiBodyManager
{
public:

private:
	CentiBodyManager() {};
	
	static CentiBodyManager* GetInstance();

	static CentiBodyManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIBODY_MANAGER
