#pragma once
#include "../../game/game.hpp"
#include <fstream>
#include <io.h>

class SaveManager {
public:
	static void createSave();
	static void loadSave();
	static void updateSave(int saveNr, std::string player, int sex, std::string chapter, int stage);
	static void loadSaveInfo(std::string save);
	static void printSavesList();
	static void searchforSaves();
	static std::string printSex(int sex);
};