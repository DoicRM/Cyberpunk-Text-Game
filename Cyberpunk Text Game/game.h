#pragma once
#include <string>
#include "fraction.h"
#include "item.h"
#include "weapon.h"
#include "clothes.h"
#include "hero.h"
#include "npc.h"
#include "quest.h"
#include "events.h"
#include "functions.h"
#include "location.h"
#include "logger.h"

class Game
{
private:
	bool playing;
	int menu, choice, gameLang;
	Location* ptrCurrentLocation;

public:
	Game();
	virtual ~Game();

	void run(); // rozpoczêcie dzia³ania
	void init(); // inicjalizacja obiektów
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
	void setCurrentLocation(Location* location) { this->ptrCurrentLocation = location; } // ustawienie aktualnej lokacji

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->ptrCurrentLocation; }
}; 