#pragma once
#include "../utilities.hpp"
#include <array>

class Menu
{
public:
	Menu();
	virtual ~Menu();

	void actionOption(int nr, std::string text); // tworzenie akcji gracza - (numer, opis)
	static void showHeroAction(std::string text); // wyświetlanie akcji gracza - (opis)
	void showHeroChoice();
	void clearOptions();
	void addOption(std::string description);
	void addOptions(std::vector<std::string> options);
	void showOptions();
	int inputChoice();

	inline int getChoice() const { return this->choice; }

private:
	int optionNr;
	int choice;
	std::map <int, std::string> options;
};