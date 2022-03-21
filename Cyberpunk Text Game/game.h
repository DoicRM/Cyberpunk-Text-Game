#pragma once
#include <string>
#include "fraction.h"
#include "item.h"
#include "weapon.h"
#include "armor.h"
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

	void run();
	void selectLanguage(); // wybór jêzyka gry
	void welcome(); // powitanie
	void writeLogo(); // wypisywanie loga gry
	void mainMenu(); // menu g³ówne
	void newGame(); // nowa gra
	void continueGame(); // kontynuacja rozgrywki
	void changeLanguage(); // zmiana jêzyka gry
	void credits(); // o autorze
	void logo(); // wypisane logo gry
	void endGame(); // koniec rozgrywki
	void test();
	inline void end() { this->playing = false; }
	inline void setCurrentLocation(Location* location) { this->ptrCurrentLocation = location; }

	friend void initAll();
	friend void Function::initHeroEQ();
	friend void Function::initQuestsList();

	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }
	inline Location* getCurrentLocation() const { return this->ptrCurrentLocation; }
}; 