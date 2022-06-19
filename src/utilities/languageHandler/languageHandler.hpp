#pragma once
#include "../utilities.hpp"
#include "../../../include/nlohmann-json/json.hpp"
#include <string>
#include <filesystem>

class LanguageHandler
{
public:
	static void loadDataFromFile(int lang);
private:
	static std::string getFileName(int lang);
};

extern nlohmann::json jWriter;