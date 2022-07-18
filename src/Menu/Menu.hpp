#pragma once
#include "../Utilities/Utilities.hpp"
#include <array>
#include <functional>
#include <map>

class Menu
{
public:
	Menu();
	Menu(std::vector<std::pair<std::string, std::function<void()>>> options);
	virtual ~Menu();

	void actionOption(int nr, std::string text);
	void showHeroChoice();
	void clearOptions();
	void addOptions(std::vector<std::pair<std::string, std::function<void()>>> options);
	void showOptions();
	void inputChoice();
	int getInputChoice();
	void callFunction();

	inline int getChoice() const { return this->choice; }
	inline size_t getOptionsSize() const { return this->options.size(); }

private:
	int optionNr;
	int choice;
	std::map <int, std::pair<std::string, std::function<void()>>> options;
};