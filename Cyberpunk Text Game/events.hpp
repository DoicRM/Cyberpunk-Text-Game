#pragma once
#include "game.hpp"
#include <map>

class Event
{
public:
	static void darkAlley();
	static void street();
	static void gunShop();
	static void nightclub();
	static void sleepersHideout();

	static void heroDeath(); // ekran œmierci
	static void loadingFiles(); // ³adowanie plików
	static void gameOver(); // koniec gry
	static void clearInstances(); // czyszczenie map z instancjami
	static void namingHero(); // nadawanie bohaterowi imienia

private:
	//	Mroczny zau³ek
	static void prologue();
	static void storyIntroduction();
	static void wakeUpInDarkAlley();
	static void acceleratorFinding();
	static void rubbishSearch();
	static void outOfTheAlley();
	static void dialogueWithBob();
	static void darkAlleyCrossroads();
	//	Ulica
	static void lookAtAmnesia();
	static void meetingWithSecurityGuards();
	static void meetingWithPolicemans();
	static void streetCrossroads();
	//	Sklep z broni¹
	static void encounterGunStore();
	static void enterGunShop();
	static void zedTrade();
	static void buyPistol();
	static void dialogueWithZed();
	static void gunShopCrossroads();
	//	Klub nocny
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
	static void nightclubCrossroads();
	//	Kryjówka Œni¹cych
	static void actOne();
};

extern bool darkAlleyWasVisited, streetWasVisited, gunShopWasVisited, nightclubWasVisited, bobRecommendsZed, zedKnowsAboutBobAndZed, heroIsOnDanceFloor, heroIsAtBar, heroKnowsVincentCode;
extern int heroChoice;
