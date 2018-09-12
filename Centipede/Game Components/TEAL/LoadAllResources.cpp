// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../Splash.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new Splash() );

}

