#pragma once
#include "fraction.hpp"
#include "item.hpp"
#include "weapon.hpp"
#include "clothes.hpp"
#include "hero.hpp"
#include "npc.hpp"
#include "quest.hpp"
#include "events.hpp"
#include "utilities.hpp"
#include "location.hpp"
#include "logger.hpp"

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
	static void initQuestsList(); // zadañ gracza
	// zatrzymanie gry
	static void pause();

	void run(); // rozpoczêcie dzia³ania
	void initAll(); // inicjalizacja obiektów
	void selectLanguage(); // wybór jêzyka
	void welcome(); // powitanie
	void writeLogo(); // wypisywanie loga
	void mainMenu(); // menu g³ówne
	void newGame(); // nowa gra
	void continueGame(); // kontynuacja rozgrywki
	void changeLanguage(); // zmiana jêzyka
	void credits(); // o autorze
	void logo(); // wypisane logo
	void endGame(); // koniec rozgrywki
	void test(); // do testów
	void end() { this->playing = false; } // zakoñczenie dzia³ania
	void setCurrentLocation(Location* location); // ustawienie aktualnej lokacji
	void startEventsByLocation(); // ustawienie aktualnej lokacji

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->ptrCurrentLocation; }

	static std::map <int, Game> game;
}; 