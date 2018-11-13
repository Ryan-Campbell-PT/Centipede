#include "CentiHeadManager.h"
#include "CentiHeadFactory.h"
#include "CentipedeHead.h"
#include "MoveFSM.h"

#include <random>
#include "MushroomManager.h"
#include "WaveManager.h"
#include "CentiHeadPool.h"

CentiHeadManager * CentiHeadManager::instance = nullptr;

void CentiHeadManager::InitializeCentipede(const int &numBodies, const float &centiSpeed,
	const int &numSoloHeads, const float &soloHeadSpeed)
{
	GetInstance()->SetApi(numBodies, instance->checkSpeed(centiSpeed), numSoloHeads, instance->checkSpeed(soloHeadSpeed));

	instance->reinitializeCenti();
}

int CentiHeadManager::checkSpeed(const float& speed) const
{
	int ret;

	if(speed <= static_cast<int>(CentiSpeeds::One))
		ret = static_cast<int>(CentiSpeeds::One);

	else if(speed >= static_cast<int>(CentiSpeeds::One) && speed <= static_cast<int>(CentiSpeeds::Two))
		ret = static_cast<int>(CentiSpeeds::Two);

	else if(speed >= static_cast<int>(CentiSpeeds::Two) && speed <= static_cast<int>(CentiSpeeds::Four))
		ret = static_cast<int>(CentiSpeeds::Four);

	else if(speed >= static_cast<int>(CentiSpeeds::Four) && speed <= static_cast<int>(CentiSpeeds::Eight))
		ret = static_cast<int>(CentiSpeeds::Eight);

	else //anything greater than 8
		ret = static_cast<int>(CentiSpeeds::Sixteen);

	return ret;
}


CentipedeHead* CentiHeadManager::GetCentiHead()
{
	return CentiHeadFactory::GetCentiHead();
}

void CentiHeadManager::InitializeHead(CentipedeHead * head, const sf::Vector2f & pos, const CentipedeDirectionState & direction)
{
	head->InitializeHead(pos, instance->centiSpeed, direction);
}

void CentiHeadManager::RestartWave()
{
	CentiHeadFactory::EndWave();
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

void CentiHeadManager::SetApi(const int &numBodies, const int &centiSpeed,
		const int &numSoloHeads, const int &soloHeadSpeed)
{
	this->numBodies = numBodies;
	this->centiSpeed = centiSpeed;
	this->numSoloHeads = numSoloHeads;
	this->soloHeadSpeed = soloHeadSpeed;
}

void CentiHeadManager::SpawnSoloHeads()
{
	auto pos = sf::Vector2f(0.f, 0.f);
	bool spawnOnLeft = false;
	for(int i = 0 ; i < GetInstance()->numSoloHeads; ++i)
	{
		spawnOnLeft = rand() % 2;
		if(spawnOnLeft)
			pos.x = 0.f;
		else
			pos.x = static_cast<float>(WindowManager::MainWindow.getSize().x);

		pos.y = static_cast<float>(rand() % static_cast<int>(WindowManager::MainWindow.getSize().y));

		const auto head = CentiHeadFactory::GetCentiHead();
		if(spawnOnLeft)
			head->InitializeHead(pos, instance->soloHeadSpeed, MoveSFM::rightThenDown);
		else			
			head->InitializeHead(pos, instance->soloHeadSpeed, MoveSFM::leftThenDown);
	}
}

void CentiHeadManager::reinitializeCenti() const
{
	auto head = CentiHeadFactory::GetCentiHead();
	head->InitializeHead(sf::Vector2f(WindowManager::MainWindow.getSize().x / 2.f, 0.f), numBodies, centiSpeed, MoveSFM::downThenLeft);
}

CentiHeadManager * CentiHeadManager::GetInstance()
{
	if (instance == nullptr)
		instance = new CentiHeadManager;

	return instance;
}
