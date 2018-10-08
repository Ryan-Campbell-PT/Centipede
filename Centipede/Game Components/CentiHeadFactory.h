#ifndef CENTIBODY_FACTORY
#define CENTIBODY_FACTORY

//#include <list>
//using std::list;

class CentipedeHead;

class CentiHeadFactory
{
public:
	static CentipedeHead* GetCentiHead();
	static void RemoveCentiHead(CentipedeHead *const head);

private:
	CentiHeadFactory() {};

	static CentiHeadFactory* GetInstance();

	static CentiHeadFactory* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIHEAD_FACTORY
