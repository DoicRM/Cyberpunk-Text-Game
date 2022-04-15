#pragma once
#include "../utilities.hpp"

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
	void showOptions();
	int getChoice();

	static std::map <int, Menu> menus;

private:
	int optionNr;
	int choice;
	std::map <int, std::string> options;
};