#pragma once
#include "../utilities.hpp"
#include "../json.hpp"
#include <string>
#include <filesystem>

class JSON
{
public:
	static void loadFile(int lang);
	static std::string getValue(std::string key);
};

extern nlohmann::json j;