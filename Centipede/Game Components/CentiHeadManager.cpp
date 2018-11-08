#include "CentiHeadManager.h"
#include "CentiHeadFactory.h"
#include "CentipedeHead.h"
#include "MoveFSM.h"

#include <random>
#include "MushroomManager.h"
#include "WaveManager.h"
#include "CentiHeadPool.h"

CentiHeadManager * CentiHeadManager::instance = nullptr;

void CentiHeadManager::InitializeCentipede(const int numBodies, const float centiSpeed, 
		const int numSoloHeads, const float soloHeadSpeed)
{
	GetInstance()->SetApi(numBodies, centiSpeed, numSoloHeads, soloHeadSpeed);

	auto head = CentiHeadFactory::GetCentiHead();
	head->InitializeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0.f), numBodies, MoveSFM::downThenLeft);
	instance->numActiveCenti++;
}

CentipedeHead* CentiHeadManager::GetCentiHead()
{
	return CentiHeadFactory::GetCentiHead();
}

/*void CentiHeadManager::RemoveCentiHead(CentipedeHead * const head)
{
	if(--GetInstance()->numActiveCenti <= 0) 
		WaveManager::EndWave(); //end round if there are no centipedes remaining
}*/

void CentiHeadManager::InitializeHead(CentipedeHead * head, const sf::Vector2f & pos, const CentipedeDirectionState & direction)
{
	GetInstance()->numActiveCenti++;
	head->InitializeHead(pos, direction);
}

void CentiHeadManager::RestartWave()
{
	//todo: remove all the bodies and heads
	CentiHeadPool::EndWave();
	//GetInstance()->InitializeCentipede(instance->numBodies, instance->centiSpeed,
		//instance->numSoloHeads, instance->soloHeadSpeed);
	GetInstance()->reinitializeCenti();
}

void CentiHeadManager::EndWave()
{
	CentiHeadFactory::EndWave();
}

void CentiHeadManager::Terminate()
{
	delete instance;
	instance = nullptr;

	CentiHeadFactory::Terminate();
}

void CentiHeadManager::SetApi(const int numBodies, const float centiSpeed,
	const int numSoloHeads, const float soloHeadSpeed)
{
	this->numBodies = numBodies;
	this->centiSpeed = centiSpeed;
	this->numSoloHeads = numSoloHeads;
	this->soloHeadSpeed = soloHeadSpeed;
}

void CentiHeadManager::SpawnSoloHeads()
{
	//if()
}

void CentiHeadManager::reinitializeCenti()
{//todo
	auto head = CentiHeadFactory::GetCentiHead();
	head->InitializeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0.f), numBodies, MoveSFM::downThenLeft);
	//head->SetAlarm(0, .5f);
	instance->numActiveCenti++;

}

CentiHeadManager * CentiHeadManager::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadManager;

	return instance;
}
