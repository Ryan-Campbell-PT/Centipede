#include "WaveManager.h"
#include <fstream>
#include <string>
#include <iostream>

WaveManager * WaveManager::GetInstance()
{
	if(instance == nullptr)
		instance = new WaveManager;

	return instance;
}

void WaveManager::GetWaveInfo(const char * filePath)
{
	std::ifstream myFile;
	std::string line;
	myFile.open(filePath);

	if(myFile.is_open())
	{
		while(std::getline(myFile, line))
		{
			
		}
	}
}
