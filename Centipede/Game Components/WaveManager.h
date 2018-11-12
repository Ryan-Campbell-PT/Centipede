#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H
#include <xstring>
#include <list>
#include "TEAL/GameObject.h"

class Glyph;
class WaveInfoWriter;

class WaveManager
{
public:
	static void LoadLevelInfo(const char* filePath);
	///will be used to initialize all the necessary info in the level specified
	static void SetupLevel(const int &levelNum);
	///this function will be used as a cleanup whenever the wave has ended
	static void EndWave();
	static int GetCurrentWave();

	static void Terminate();

private:
	struct Wave
	{
		Wave()
			:level(0) {}

		struct LevelInfo
		{
			LevelInfo()
				: centiBodyCount(0), numSoloHeads(0), centiSpeed(0.f),
				centiSoloHeadSpeed(0.f), fleaTriggerValue(0), fleaActive(false),
				scorpTimeToSpawn(0), scorpActive(false), spiderSpeed(0.f),
				spiderActive(false), spiderTimeToSpawn(0) {}


			int centiBodyCount, numSoloHeads;
			float centiSpeed, centiSoloHeadSpeed;

			int fleaTriggerValue; bool fleaActive;

			float scorpTimeToSpawn; bool scorpActive;

			float spiderSpeed; bool spiderActive; float spiderTimeToSpawn;
		};

		int level;

		LevelInfo info;
	};

	WaveManager();
	static WaveManager *GetInstance();

	void loadLevelInfo(const char *filePath);
	void setCritterSettings(const WaveManager::Wave wave);
	void endWave() const;
	void setupLevel(const int &levelNum);

	float getFloatInfo(const std::string& line) const;
	bool getBoolInfo(const std::string& line) const;
	int getIntInfo(const std::string& line) const;

	static WaveManager* instance;

	int currentLevel;
	const size_t MAX_SIZE = 100;

	std::vector<WaveManager::Wave> levelList; //this will hold all the level info for quick access



};

#endif // WAVEMANAGER_H
