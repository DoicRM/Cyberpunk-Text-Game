#pragma once
#include "../game/game.hpp"
#include <map>

class Event
{
public:
	// PROLOG
	static void darkAlley();
	static void street();
	static void gunShop();
	static void nightclub();
	// AKT I
	static void sleepersHideout();

	static void heroDeath(); // ekran �mierci
	static void loadingFiles(); // �adowanie plik�w
	static void gameOver(); // koniec gry
	static void clearInstances(); // czyszczenie map z instancjami
	static void namingHero(); // nadawanie bohaterowi imienia

private:
	// PROLOG
	// Mroczny zau�ek
	static void prologue();
	static void storyIntroduction();
	static void wakeUpInDarkAlley();
	static void acceleratorFinding();
	static void rubbishSearch();
	static void outOfTheAlley();
	static void dialogueWithBob();
	static void darkAlleyCrossroads();
	// Ulica
	static void lookAtAmnesia();
	static void meetingWithSecurityGuards();
	static void meetingWithPolicemans();
	static void wakeUpBeforeMeetingWithJet();
	static void streetCrossroads();
	// Sklep z broni�
	static void encounterGunStore();
	static void enterGunShop();
	static void zedTrade();
	static void buyPistol();
	static void dialogueWithZed();
	static void zedGetsAnAccelerator();
	static void gunShopCrossroads();
	// Klub nocny
	static void enterClub();
	static void clubDanceFloor();
	static void clubBar();
	static void miaMeeting();
	static void clubUpstairs();
	static void dialogueWithJet();
	static void jetGetsAngry(int angerPoints);
	static void vincentOffice();
	static void checkVincentDesk();
	static void vincentHideoutCode();
	static void vincentHideout();
	static void dialogueWithVincent();
	static void vincentDeath();
	static void vincentResurrection();
	static void nightclubCrossroads();
	// AKT I
	// Kryj�wka �ni�cych
	static void actOne();
	static void sleepersHideoutCrossroads();
};

extern int heroChoice;
extern bool darkAlleyWasVisited,
			streetWasVisited,
			gunShopWasVisited,
			nightclubWasVisited,
			bobRecommendsZed,
			zedKnowsAboutBobAndZed,
			heroIsOnDanceFloor,
			heroIsAtBar,
			heroKnowsVincentCode;