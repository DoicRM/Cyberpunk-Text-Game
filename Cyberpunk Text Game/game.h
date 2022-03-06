#pragma once
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
#include <string>

using namespace std;

class Game
{
private:
	bool playing;
	int menu, choice, gameLang;
	Location* ptrCurrentLocation;

public:
	Game();
	virtual ~Game();

	// funkcje
	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }

	void selectLanguage(); // wybór jêzyka gry
	void welcome(); // powitanie
	void writeLogo(); // wypisywanie loga gry
	void mainMenu(); // menu g³ówne
	void newGame(); // nowa gra
	void continueGame(); // kontynuacja rozgrywki
	void aboutAuthor(); // o autorze
	void logo(); // wypisane logo gry
	void endGame(); // koniec rozgrywki
	void credits();
	void test();

	void setCurrentLocation(Location* location);
	Location* getCurrentLocation();

	friend void initAll();
	friend void Function::initHeroEQ();
	friend void Function::initQuestsList();
}; 

enum language
{
	en = 1,
	pl = 2
};