#ifndef CENTIBODY_FACTORY
#define CENTIBODY_FACTORY

//#include <list>
//using std::list;

class CentipedeHead;

class CentiHeadFactory
{
public:
	static CentipedeHead* GetCentiHead();

	CentiHeadFactory &operator=(const CentiHeadFactory &c) = delete;
	CentiHeadFactory(const CentiHeadFactory &c) = delete;
	static void EndWave();

	static void Terminate();

	private:
	CentiHeadFactory() = default;
	virtual ~CentiHeadFactory() = default;

	static CentiHeadFactory* GetInstance();

	static CentiHeadFactory* instance;
	//std::list<CentipedeHead*> headList;
};



#endif // !CENTIHEAD_FACTORY
