#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER
#include "TEAL/CommonElements.h"
#include "CentiBodyManager.h"

class CentipedeHead;

class CentiHeadManager
{
public:
	///this is used to initialize a full centipede
	static void InitializeCentipede(const int &numBodies, const float &centiSpeed,
		const int &numSoloHeads, const float &soloHeadSpeed);

	static CentipedeHead* GetCentiHead();
	//static void RemoveCentiHead(CentipedeHead * const head);
	///this is used to initialize a body to a head
	static void InitializeHead(CentipedeHead* head, const sf::Vector2f& pos, const CentipedeDirectionState& direction);

	CentiHeadManager(const CentiHeadManager &s) = delete;
	CentiHeadManager operator = (const CentiHeadManager &) = delete;

	static void RestartWave();
	static void EndWave();
	static void Terminate();

private:
	CentiHeadManager() = default;
	virtual ~CentiHeadManager() = default;

	void SetApi(const int &numBodies, const int &centiSpeed,
		const int &numSoloHeads, const float &soloHeadSpeed);
	int checkSpeed(const float &speed) const;
	void SpawnSoloHeads();
	void reinitializeCenti() const;

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
	//todo: solo heads spawning
	///api stuff
	int numBodies;
	int centiSpeed;
	int numSoloHeads;
	float soloHeadSpeed;

	enum class CentiSpeeds
	{
		One = 1,
		Two = 2,
		Four = 4,
		Eight = 8,
		Sixteen = 16
	};
};



#endif // !CENTIHEAD_MANAGER
