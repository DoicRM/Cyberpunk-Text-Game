#pragma once
#include "hero.h"
#include "npc.h"
#include "fraction.h"
#include "item.h"
#include "quest.h"
#include "events.h"
#include "functions.h"
#include "location.h"
#include <string>
#include <map>

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	// funkcje
	inline bool getPlaying() const { return this->playing; }
	inline int getLang() const { return this->gameLang; }

	void selectLanguage(); // Wybór jêzyka gry
	void welcome(); // Powitanie
	void writeLogo(); // Wypisywanie loga gry
	void mainMenu(); // Menu g³ówne
	void newGame(); // Nowa gra
	void continueGame(); // Kontynuacja rozgrywki
	void aboutAuthor(); // O autorze
	void logo(); // Gotowe logo gry
	void endGame(); // Koniec rozgrywki
	void credits();

	friend void initAll();
	friend void Function::initHeroEQ();
	friend void Function::initQuestsList();

private:
	bool playing;
	int menu, choice, gameLang;
	Location* ptrCurrentLocation;
}; 

enum language
{
	en = 1,
	pl = 2
};