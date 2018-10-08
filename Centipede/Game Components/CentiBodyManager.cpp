#include "CentiBodyManager.h"
#include "CentiBodyFactory.h"
#include "CentipedeBody.h"

CentiBodyManager * CentiBodyManager::instance = 0;

CentipedeBody * CentiBodyManager::GetCentiBody()
{
	return CentiBodyFactory::GetCentiBody(GetInstance());
}

CentipedeBody * CentiBodyManager::GetInitializedCentiBody(sf::Vector2f const & pos, CentiMovementDirectionEnum const & direction)
{
	auto body = CentiBodyFactory::GetCentiBody(GetInstance());
	body->InitializeBody(pos, direction);

	return body;
}

CentiBodyManager * CentiBodyManager::GetInstance()
{
	if(instance == 0)
		instance = new CentiBodyManager;

	return instance;
}
