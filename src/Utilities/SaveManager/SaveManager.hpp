#pragma once
#include "../../Game/Game.hpp"
#include <filesystem>
#include <fstream>
#include <io.h>

struct Save {
	std::string date,
		hour,
		player;
	int chapter, gender, stage;
};

class SaveManager {
public:
	static void createSave();
	static void loadSave(int nr);
	static void updateSave(int saveNr, std::string player, int sex, int chapter, int stage);
	static void printSavesList();
	static std::string printSex(int sex);
private:
	static std::string getChapterString(int chapter);
	static void loadSaveInfo(std::string saveToLoad);
	static void searchForSaves();
};
