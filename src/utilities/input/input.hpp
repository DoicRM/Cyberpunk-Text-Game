#pragma once
#include "../display/display.hpp"
#include "../logger/logger.hpp"
#include <string>

class Input
{
public:
	static int getChoice();
	static std::string getString();
};
