#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER

//#include <list>
//using std::list;

class CentipedeHead;

class CentiHeadManager
{
public:

private:
	CentiHeadManager() {};

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIHEAD_MANAGER
