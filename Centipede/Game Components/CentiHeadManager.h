#ifndef CENTIHEAD_MANAGER
#define CENTIHEAD_MANAGER
#include <SFML/System/Vector2.hpp>
#include "CentiBodyManager.h"

class CentipedeHead;

class CentiHeadManager
{
public:
	///this is used to initialize a full centipede
	static void InitializeCentipede(const int numBodies, const float centiSpeed, 
		const int numSoloHeads, const float soloHeadSpeed);

	static CentipedeHead* GetCentiHead();
	static void RemoveCentiHead(CentipedeHead * const head);
	///this is used to initialize a body to a head
	static void InitializeHead(CentipedeHead* head, const sf::Vector2f& pos, const CentipedeDirectionState& direction);

	CentiHeadManager(const CentiHeadManager &s) = delete;
	CentiHeadManager operator = (const CentiHeadManager &) = delete;
	static void EndWave();

private:
	CentiHeadManager() = default;
	virtual ~CentiHeadManager() { delete instance; }

	void SetApi(const int numBodies, const float centiSpeed,
		const int numSoloHeads, const float soloHeadSpeed);
	void SpawnSoloHeads();

	static CentiHeadManager* GetInstance();

	static CentiHeadManager* instance;
	//todo: solo heads spawning
	///api stuff
	int numBodies;
	float centiSpeed;
	int numSoloHeads;
	float soloHeadSpeed;

	int numActiveCenti = 0;
};



#endif // !CENTIHEAD_MANAGER
