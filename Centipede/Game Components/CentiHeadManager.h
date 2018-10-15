#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER

class CentipedeHead;

class CentiHeadManager
{
public:
	static void InitializeCentipede(const int numBodies, const float centiSpeed, 
		const int numSoloHeads, const float soloHeadSpeed);

	static CentipedeHead* GetCentiHead();
	static void RemoveCentiHead(CentipedeHead * const head);

private:
	CentiHeadManager() = default;
	void SetApi(const int numBodies, const float centiSpeed,
		const int numSoloHeads, const float soloHeadSpeed);

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
	//todo: solo heads spawning
	///api stuff
	int numBodies;
	float centiSpeed;
	int numSoloHeads;
	float soloHeadSpeed;
};



#endif // !CENTIHEAD_MANAGER
