#include "CentiHeadManager.h"
#include "CentiHeadFactory.h"
#include "CentipedeHead.h"
#include "MoveFSM.h"

#include <random>
#include "MushroomManager.h"

CentiHeadManager * CentiHeadManager::instance = 0;

void CentiHeadManager::InitializeCentipede()
{
	auto head = CentiHeadFactory::GetCentiHead();

	//this can be changed in the future. for now i will keep it as a random number
	//head->InitializeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0.f), rand() % MAX_CENTI_BODY, MoveSFM::downThenLeft);
	head->InitializeHead(sf::Vector2f(200, 200), rand() % MAX_CENTI_BODY, MoveSFM::downThenLeft);
}

CentipedeHead* CentiHeadManager::GetCentiHead()
{
	return CentiHeadFactory::GetCentiHead();
}

void CentiHeadManager::RemoveCentiHead(CentipedeHead * const head)
{
	CentiHeadFactory::RemoveCentiHead(head);
	MushroomManager::AttemptSpawnShroom(head->GetPosition());
}

CentiHeadManager * CentiHeadManager::GetInstance()
{
	if (instance == 0)
		instance = new CentiHeadManager;

	return instance;
}
