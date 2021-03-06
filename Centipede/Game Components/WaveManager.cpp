#include "WaveManager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "TEAL/Tools.h"
#include <list>
#include "Ship.h"
#include "CentiHeadManager.h"
#include "FleaManager.h"
#include "ScorpionManager.h"
#include "SpiderManager.h"
#include "MushroomManager.h"
#include "TextEditor.h"
#include "GameGrid.h"
#include "WaveWriter.h"

WaveManager * WaveManager::instance = nullptr;

WaveManager::WaveManager()
	:currentLevel(0)
{
}

WaveManager * WaveManager::GetInstance()
{
	if (instance == nullptr)
		instance = new WaveManager;

	return instance;
}

void WaveManager::loadLevelInfo(const char * filePath)
{
	std::ifstream myFile;
	std::string line;
	myFile.open(filePath);

	Wave wave;

	while (std::getline(myFile, line))
	{
		if(line.empty())
			continue; //save a couple computations

		//transform to lower, for simplicity
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);

		if (line.find("level") < MAX_SIZE) //MAX_SIZE bc if false, returns huge number
		{//we are currently trying to find the level
			wave.level = this->getIntInfo(line);
		}

		else if (line.find("spider") < MAX_SIZE)
		{
			if (line.find("speed") < MAX_SIZE)
				wave.info.spiderSpeed = this->getFloatInfo(line);

			else if (line.find("active") < MAX_SIZE)
				wave.info.spiderActive = this->getBoolInfo(line);

			else if (line.find("spawn") < MAX_SIZE)
				wave.info.spiderTimeToSpawn = this->getFloatInfo(line);
		}

		else if (line.find("centi") < MAX_SIZE)
		{
			if (line.find("numsolo") < MAX_SIZE)
				wave.info.centiSoloHeadSpeed = this->getFloatInfo(line);

			else if (line.find("centispeed") < MAX_SIZE)
				wave.info.centiSpeed = this->getFloatInfo(line);

			else if (line.find("soloheadspeed") < MAX_SIZE)
				wave.info.centiSoloHeadSpeed = this->getFloatInfo(line);

			else if (line.find("bodycount") < MAX_SIZE)
				wave.info.centiBodyCount = this->getIntInfo(line);
		}

		else if (line.find("flea") < MAX_SIZE)
		{
			if (line.find("active") < MAX_SIZE)
				wave.info.fleaActive = this->getBoolInfo(line);

			else if (line.find("spawn") < MAX_SIZE)
				wave.info.fleaTriggerValue = this->getIntInfo(line);
		}

		else if (line.find("scorpion") < MAX_SIZE)
		{
			if (line.find("active") < MAX_SIZE)
				wave.info.scorpActive = this->getBoolInfo(line);

			else if (line.find("spawn") < MAX_SIZE)
				wave.info.scorpTimeToSpawn = this->getFloatInfo(line);
		}

		else if (!line.empty() && line[0] == '_')
		{//this will signify we have ended that levels info
			this->levelList.push_back(wave);
			wave = Wave();
		}
	}

	myFile.close();

	//at the beginnning of the game, we assume we are in attractor mode
	//PlayerManager::SetPlayerMode(PlayerData::PlayerID::Ai);
}

float WaveManager::getFloatInfo(const std::string& line) const
{
	return std::stof( //convert it to a float
		line.substr( //create a substring starting at the space, and ending at the end (just the number)
			line.find(' '), //find the position of the space, indicating a number will be after it
			line.size())); //get the entire size of the line, to take us to the end of it
}

bool WaveManager::getBoolInfo(const std::string& line) const
{
	return line.find("yes") < MAX_SIZE;
}

int WaveManager::getIntInfo(const std::string& line) const
{
	return std::stoi(
		line.substr(
			line.find(' '),
			line.size()));
}

int WaveManager::GetCurrentWave()
{
	return GetInstance()->currentLevel;
}

void WaveManager::Terminate()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void WaveManager::LoadLevelInfo(const char * filePath)
{
	GetInstance()->loadLevelInfo(filePath);
}

void WaveManager::SetupLevel(const int & levelNum)
{
	GetInstance()->setupLevel(levelNum);
}

void WaveManager::setupLevel(const int& levelNum)
{
	Wave curWave;
	if(levelNum > static_cast<int>(this->levelList.size()))
		curWave = this->levelList[0]; //if the designers didnt set upaa this level, just load attractor data

	else
		curWave = this->levelList[levelNum];
	
	GetInstance()->setCritterSettings(curWave);
	this->currentLevel = levelNum;
	WaveWriter::WriteWave(levelNum);
}

void WaveManager::EndWave()
{
	GetInstance()->endWave();
}

void WaveManager::endWave() const
{
	MushroomManager::EndWave();

	CentiBodyManager::EndWave();
	CentiHeadManager::EndWave();
	FleaManager::EndWave();
	ScorpionManager::EndWave();
	SpiderManager::EndWave();
}

void WaveManager::setCritterSettings(const WaveManager::Wave wave)
{
	//todo: may want to as well set collision depeding on whos avalble
	CentiHeadManager::InitializeCentipede(wave.info.centiBodyCount, wave.info.centiSpeed,
		wave.info.numSoloHeads, wave.info.centiSoloHeadSpeed); //assign info for centi

	if (wave.info.fleaActive)
		FleaManager::InitializeFlea(wave.info.fleaTriggerValue);
	else
		FleaManager::DeInitializeFlea(); //if this level doesnt have that critter, dont spawn it

	if (wave.info.scorpActive)
		ScorpionManager::InitializeScorpion(wave.info.scorpTimeToSpawn);
	else
		ScorpionManager::DeInitializeScorpion();

	if (wave.info.spiderActive)
		SpiderManager::InitializeSpider(wave.info.spiderTimeToSpawn, wave.info.spiderSpeed);
	else
		SpiderManager::DeInitializeSpider();

	this->currentLevel = wave.level;
}
