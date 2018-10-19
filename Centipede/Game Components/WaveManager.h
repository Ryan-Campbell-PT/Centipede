#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H
#include <xstring>

class WaveManager
{
public:
	static void GetWaveInfo(const char* filePath);
	
private:
	static WaveManager *GetInstance();
	void getWaveInfo(const char *filePath);

	float getFloatInfo(const std::string& string, const std::string& line) const;
	bool getBoolInfo(const std::string& line) const;
	int getIntInfo(const std::string& string, const std::string& line) const;

	static WaveManager* instance;

	unsigned int currentLevel;
	const size_t MAX_SIZE = 100;

	struct Wave
	{
		struct LevelInfo
		{
			float spiderSpeed; bool spiderActive;

			int centiBodyCount, numSoloHeads;
			float centiSpeed, centiSoloHeadSpeed;


		};
		
		int level;

		LevelInfo info;
		
	};
};

#endif // WAVEMANAGER_H
