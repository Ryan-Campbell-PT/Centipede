#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER

#define MAX_CENTI_BODY 6

class CentipedeHead;

class CentiHeadManager
{
public:
	static void InitializeCentipede();

	static CentipedeHead* GetCentiHead();
	static void RemoveCentiHead(CentipedeHead * const head);

private:
	CentiHeadManager() = default;

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
};



#endif // !CENTIHEAD_MANAGER
