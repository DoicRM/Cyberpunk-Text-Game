#pragma once
#include "../utilities.hpp"
#include <array>
#include <functional>

class Menu
{
public:
	Menu();
	virtual ~Menu();

	void actionOption(int nr, std::string text); // tworzenie akcji gracza - (numer, opis)
	static void showHeroAction(std::string text); // wyświetlanie akcji gracza - (opis)
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