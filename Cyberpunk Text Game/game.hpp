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
	static void initQuestsList(); // zada� gracza
	// zatrzymanie gry
	static void pause();

	void run(); // rozpocz�cie dzia�ania
	void initAll(); // inicjalizacja obiekt�w
	void selectLanguage(); // wyb�r j�zyka
	void welcome(); // powitanie
	void writeLogo(); // wypisywanie loga
	void mainMenu(); // menu g��wne
	void newGame(); // nowa gra
	void continueGame(); // kontynuacja rozgrywki
	void changeLanguage(); // zmiana j�zyka
	void credits(); // o autorze
	void logo(); // wypisane logo
	void endGame(); // koniec rozgrywki
	void test(); // do test�w
	void end() { this->playing = false; } // zako�czenie dzia�ania
	void setCurrentLocation(Location* location); // ustawienie aktualnej lokacji
	void startEventsByLocation(); // ustawienie aktualnej lokacji

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->ptrCurrentLocation; }

	static std::map <int, Game> game;
}; 