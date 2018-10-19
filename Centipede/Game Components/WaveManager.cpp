#include "WaveManager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "TEAL/Tools.h"
#include <list>

WaveManager * WaveManager::instance = nullptr;

WaveManager * WaveManager::GetInstance()
{
	if (instance == nullptr)
		instance = new WaveManager;

	return instance;
}

void WaveManager::getWaveInfo(const char * filePath)
{	
	std::ifstream myFile;
	std::string line;
	myFile.open(filePath);
	size_t charInstance = 0;
	int levelNumber = 0;
	std::list<Wave> waveInfo;

#if true
	//if(myFile.is_open())
	Wave wave;

	while (std::getline(myFile, line))
	{
		//transform to lower, for portability
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);

		if ((charInstance = line.find("level")) < MAX_SIZE) //found it (100 bc if false, returns huge number)
		{//we are currently trying to find the level
			//charInstance = std::size("level"); //take us to the spot past where "level" is
			//levelNumber = std::stoi(line.substr(charInstance, std::size(line))); //create a substring of the remaining numbers after the space and turn it into a number
			wave.level = this->getIntInfo("level", line);
		}

		else if ((charInstance = line.find("spider")) < MAX_SIZE)
		{
			if(line.find("spiderspeed") < MAX_SIZE)
			{
				//charInstance = std::size("speed");
				//wave.info.spiderSpeed = std::stof(line.substr(charInstance, std::size(line)));
				wave.info.spiderSpeed = this->getFloatInfo("speed", line);
			}

			else if(line.find("active") < MAX_SIZE)
			{
				//charInstance = std::size("spideractive");
				//wave.info.spiderActive = std::stoi(line.substr(charInstance, std::size(line)));
				/*if(line.find("yes"))
					wave.info.spiderActive = true;
				else 
					wave.info.spiderActive = false;*/
				wave.info.spiderActive = this->getBoolInfo("active");
			}

			else if(line.find("centi") < MAX_SIZE)
			{
				if(line.find("numsolo") < MAX_SIZE)
					//wave.info.centiSoloHeadSpeed = std::stoi(line.substr(charInstance, std::size(line)));
					wave.info.centiSoloHeadSpeed = this->getIntInfo("numsolo", line);

				else if(line.find("centispeed") < MAX_SIZE)
					//wave.info.centiSpeed = std::stof(line.substr(charInstance, std::size(line)));
					wave.info.centiSpeed = this->getFloatInfo("centispede", line);
				
				else if(line.find("soloheadspeed") < MAX_SIZE)
					//wave.info.centiSoloHeadSpeed= std::stof(line.substr(charInstance, std::size(line)));
					wave.info.centiSoloHeadSpeed = this->getFloatInfo("soloheadspeed", line);
			}

			else if(line.find('-'))
			{//this will signify we have ended that levels info
				waveInfo.push_back(wave);
			}
		}
	}

#endif

}

float WaveManager::getFloatInfo(const std::string& string, const std::string& line) const
{
	return std::stof(line.substr(std::size(string), std::size(line)));
}

bool WaveManager::getBoolInfo(const std::string& line) const
{
	return line.find("yes") < MAX_SIZE;
}

int WaveManager::getIntInfo(const std::string& string, const std::string& line) const
{
	return std::stoi(line.substr(std::size(string), std::size(line)));
}

void WaveManager::GetWaveInfo(const char * filePath)
{
	GetInstance()->getWaveInfo(filePath);
}
