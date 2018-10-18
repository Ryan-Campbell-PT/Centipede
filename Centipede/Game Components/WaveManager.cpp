#include "WaveManager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "TEAL/Tools.h"

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
	auto g = myFile.is_open();
	size_t charInstance = 0;
	size_t levelValue = 0;

#if true
  	//if(myFile.is_open())
	
		while(std::getline(myFile, line))
		{
			
				size_t first(0), second(8), third(7);
			//transform to lower, for portability
			std::transform(line.begin(), line.end(), line.begin(), ::tolower); 
			if((charInstance = line.find("level")) < 100) //found it (100 bc if false, returns huge number)
			{//we are currently trying to find the level
				charInstance += std::size("level"); //take us to the spot past where "level" is

				auto s = std::stoi(line, &first); 
				auto p = std::stoi(line, &second); 
				auto y = std::stoi(line, &third);
				auto gar = 9;
				//levelValue = line[charInstance] - '0'; //convert the character to an integer todo: will not work for numbrers > 9
				//auto a = std::stoi(line, &charInstance); //and request to find the number, after charInstance
				//auto i = 0;
			}
		}
	
#endif

}
