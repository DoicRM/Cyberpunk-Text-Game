#pragma once
#include <map>
#include "game.h"

class Event
{
public:
	static void darkAlley();
	static void street();
	static void gunShop();
	static void nightclub();

	static void heroDeath(); // ekran œmierci
	static void loadingFiles(); // ³adowanie plików
	static void gameOver(); // koniec gry

private:
	// Mroczny zau³ek
	static void darkAlleyCrossroads();
	static void prologue();
	static void storyIntroduction();
	static void wakeUpInDarkAlley();
	static void rubbishSearch();
	static void outOfTheAlley();
	static void dialogueWithBob();
	//	Ulica
	static void streetCrossroads();
	static void lookAtAmnesia();
	static void meetingWithSecurityGuards();
	static void meetingWithPolicemans();
	//	Sklep z broni¹
	static void gunShopCrossroads();
	static void encounterGunStore();
	static void enterGunShop();
	static void zedTrade();
	static void buyPistol();
	static void dialogueWithZed();
	//	Klub nocny
	static void nightclubCrossroads();
	static void enterClub();
	static void clubDanceFloor();
	static void clubBar();
	static void miaMeeting();
	static void clubUpstairs();
	static void dialogueWithJet();
	static void vincentAssassination();
	static void vincentOffice();
	static void checkVincentDesk();
	static void vincentHideoutCode();
	static void vincentHideout();
	static void dialogueWithVincent();
	static void vincentResurrection();
};

extern bool darkAlleyWasVisited, streetWasVisited, gunShopWasVisited, nightclubWasVisited, bobRecommendsZed, zedKnowsAboutBobAndZed, heroIsOnDanceFloor, heroIsAtBar, heroKnowsVincentCode;
extern int heroChoice, optionNr;
