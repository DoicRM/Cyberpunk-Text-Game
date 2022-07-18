#pragma once
#include "../../Utilities/Logger/Logger.hpp"
#include "../../Utilities/JsonHandler/JsonHandler.hpp"
#include "../../Utilities/Utilities.hpp"
#include <string>
#include <filesystem>
#include <windows.h>
#include <Lmcons.h>

class GameSettings {
public:
	static int lang;

	GameSettings();
	~GameSettings();

	bool loadConfigFile();
	static void createConfigFile();
	static void loadDataFromFile(int lang);
	static int selectLanguage();
private:
	static std::string getFileName(int lang);
};
