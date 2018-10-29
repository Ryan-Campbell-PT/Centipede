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
	static CentipedeBody* GetCentiBody();

private:
	CentiBodyFactory() = default;
	~CentiBodyFactory() { delete instance; }

	static CentiBodyFactory* GetInstance();

	static CentiBodyFactory* instance;
	//std::list<CentipedeHead*> headList;
};



#endif // !CENTIHEAD_FACTORY
