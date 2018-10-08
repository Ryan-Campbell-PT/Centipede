#ifndef CENTIHEAD_FACTORY
#define CENTIHEAD_FACTORY

//#include <list>
//using std::list;

class CentipedeBody;

class CentiBodyFactory
{
public:

private:
	CentiBodyFactory() {};

	static CentiBodyFactory* GetInstance();

	static CentiBodyFactory* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIHEAD_FACTORY
