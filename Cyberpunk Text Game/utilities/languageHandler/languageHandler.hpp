#pragma once
#include "../utilities.hpp"
#include "../json.hpp"
#include <string>
#include <filesystem>

class JSON
{
public:
	static void loadFile(int lang);
};

extern nlohmann::json j;