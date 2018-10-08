#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER

//#include <list>
//using std::list;
#define MAX_CENTI_BODY 6

class CentipedeHead;

class CentiHeadManager
{
public:
	static void InitializeCentipede();

private:
	CentiHeadManager() {};

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIHEAD_MANAGER
