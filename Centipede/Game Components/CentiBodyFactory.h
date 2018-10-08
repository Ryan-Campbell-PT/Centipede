#ifndef CENTIHEAD_FACTORY
#define CENTIHEAD_FACTORY

//#include <list>
//using std::list;

class CentipedeBody;
class CentiBodyManager;

class CentiBodyFactory
{
public:
	///the manager is only there to confirm the manager is the one requesting the objects
	static CentipedeBody* GetCentiBody(const CentiBodyManager * const d);
	static void RemoveCentiBody(const CentiBodyManager * const d, CentipedeBody *const body);

private:
	CentiBodyFactory() {};

	static CentiBodyFactory* GetInstance();

	static CentiBodyFactory* instance;
	//std::list<CentipedeHead*> bodyList;
};



#endif // !CENTIHEAD_FACTORY
