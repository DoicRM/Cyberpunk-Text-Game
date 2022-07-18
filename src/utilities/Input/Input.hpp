#pragma once
#include "../Display/Display.hpp"
#include "../Logger/Logger.hpp"
#include <string>

class Input
{
public:
	static int getChoice();
	static std::string getString();
};
