#pragma once
#include "../utilities.hpp"
#include <array>

class Menu
{
public:
	Menu();
	virtual ~Menu();

	void actionOption(int nr, std::string text); // tworzenie akcji gracza - (numer, opis)
	static void showHeroAction(std::string text); // wyœwietlanie akcji gracza - (opis)
	void showHeroChoice();
	void clearOptions();
	void addOption(std::string description);
	void addOptions(std::array<std::string, 10> options);
	void showOptions();
	int inputChoice();

	static std::map <std::string, Menu> menus;

	inline int getChoice() const { return this->choice; }

private:
	int optionNr;
	int choice;
	std::map <int, std::string> options;
};