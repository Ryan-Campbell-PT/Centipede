#include "CentiHeadManager.h"
#include "CentiHeadFactory.h"
#include "CentipedeHead.h"
#include "MoveFSM.h"

#include <random>
#include "MushroomManager.h"

CentiHeadManager * CentiHeadManager::instance = nullptr;

void CentiHeadManager::InitializeCentipede(const int numBodies, const float centiSpeed, 
		const int numSoloHeads, const float soloHeadSpeed)
{
	GetInstance()->SetApi(numBodies, centiSpeed, numSoloHeads, soloHeadSpeed);
	auto head = CentiHeadFactory::GetCentiHead();

	head->InitializeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0.f), numBodies, MoveSFM::downThenLeft);
}

CentipedeHead* CentiHeadManager::GetCentiHead()
{
	return CentiHeadFactory::GetCentiHead();
}

void CentiHeadManager::RemoveCentiHead(CentipedeHead * const head)
{
	CentiHeadFactory::RemoveCentiHead(head);
}

void CentiHeadManager::SetApi(const int numBodies, const float centiSpeed,
	const int numSoloHeads, const float soloHeadSpeed)
{
	this->numBodies = numBodies;
	this->centiSpeed = centiSpeed;
	this->numSoloHeads = numSoloHeads;
	this->soloHeadSpeed = soloHeadSpeed;
}

CentiHeadManager * CentiHeadManager::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadManager;

	return instance;
}
