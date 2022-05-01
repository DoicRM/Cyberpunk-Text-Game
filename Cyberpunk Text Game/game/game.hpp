#pragma once
#include "../fraction/fraction.hpp"
#include "../item/item.hpp"
#include "../item/weapon/weapon.hpp"
#include "../item/clothes/clothes.hpp"
#include "../hero/hero.hpp"
#include "../npc/npc.hpp"
#include "../npc/ambient/ambientNpc.hpp"
#include "../quest/quest.hpp"
#include "../events/events.hpp"
#include "../location/location.hpp"
#include "../utilities/utilities.hpp"
#include "../utilities/logger/logger.hpp"
#include "../utilities/menu/menu.hpp"
#include "../utilities/languageHandler/languageHandler.hpp"

class Game
{
private:
	bool playing;
	int menu, choice, gameLang;
	Location* ptrCurrentLocation;

public:
	Game();
	virtual ~Game();

	// inicjalizacja
	static void init(); // gry
	static void initHeroEQ(); // ekwipunku gracza
	static void initQuestsList(); // zada� gracza
	// zatrzymanie gry
	static void pause();

	void run(); // rozpoczęcie działania
	void initAll(); // inicjalizacja obiekt�w
	void selectLanguage(); // wybór języka
	void welcome(); // powitanie
	void writeLogo(); // wypisywanie loga
	void mainMenu(); // menu główne
	void newGame(); // nowa gra
	void continueGame(); // kontynuacja rozgrywki
	void changeLanguage(); // zmiana j�zyka
	void credits(); // o autorze
	void loadLogo(); // wypisane logo
	void endGame(); // koniec rozgrywki
	void end() { this->playing = false; } // zakończenie działania
	void setCurrentLocation(Location* location); // ustawienie aktualnej lokacji
	void startEventsByLocation(); // odtworzenie wydarzeń dla lokacji

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->ptrCurrentLocation; }

	static std::map <int, Game> game;

private:
	static std::array<std::string, 8> logo;
}; 