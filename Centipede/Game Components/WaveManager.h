#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H
#include <xstring>
#include <list>
#include "PlayerManager.h"
#include <SFML/System/Vector2.hpp>
#include "TEAL/GameObject.h"

class Glyph;
class WaveInfoWriter;

class WaveManager //: public GameObject
{
	/***
	 *The sole purpose of this class is to write the data from the WaveManager on the display
	 *The reason this is needed is, having WaveManager a GameObject results in TEAL creating a 
	 *GO as the scene is being created, so the resulting GO being created cannot be assigned to a scene
	 *(because it hasnt been created yet) therefor crashing the game
	 *This is a workaround for that to strictly write to the screen when i want it to
	 */
private:
	class WaveInfoWriter : public GameObject
	{
	public:
		virtual void Draw() override;
	};

public:
	static void LoadLevelInfo(const char* filePath);
	///will be used to initialize all the necessary info in the level specified
	static void SetupLevel(const int &levelNum);
	///this function will be used as a cleanup whenever the wave has ended
	static void EndWave();
	static int GetCurrentWave();

	static void WriteWaveText();

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
	//virtual void Draw() override;

	void loadLevelInfo(const char *filePath);
	void setCritterSettings(const WaveManager::Wave wave);
	void endWave() const;

	float getFloatInfo(const std::string& line) const;
	bool getBoolInfo(const std::string& line) const;
	int getIntInfo(const std::string& line) const;

	static WaveManager* instance;
	WaveInfoWriter *writer;

	sf::Vector2f waveTextPosition;
	unsigned int numGlyphsForWave;
	Glyph *waveGlyphs;

	int currentLevel;
	const size_t MAX_SIZE = 100;

	std::list<WaveManager::Wave> levelList; //this will hold all the level info for quick access




};

#endif // WAVEMANAGER_H
