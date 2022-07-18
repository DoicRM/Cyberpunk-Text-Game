#pragma once
#include "../../Game/Game.hpp"
#include <filesystem>
#include <fstream>
#include <io.h>

class SaveManager {
public:
	static void createSave();
	static void loadSave(int nr);
	static void updateSave(int saveNr, std::string player, int sex, std::string chapter, int stage);
	static void printSavesList();
	static std::string printSex(int sex);
private:
	static void loadSaveInfo(std::string save);
	static void searchForSaves();
};