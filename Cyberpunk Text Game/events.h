#pragma once
#include "game.h"
#include <map>

using namespace std;

class Event
{
public:
	static void initHero();
	static void initFractionsNpcsAndLocations();
	static void initItems();
	static void initQuests();
	static void initAll();

	// FABULARNE
	//	Mroczny zau³ek
	static void darkAlley();
		static void darkAlleyCrossroads();
		static void prologue();
		static void storyIntroduction();
		static void wakeUpAloneInDarkAlley();
		static void inSeaOfRubbish();
		static void outOfTheAlley();
		static void conversationWithHomeless();
	//	Ulica
	static void street();
		static void streetCrossroads();
		static void viewOfAmnesia();
		static void heroMeetSecurityGuards();
		static void heroMeetsPolicemans();
	//	Sklep z broni¹
	static void gunShop();
		static void gunShopCrossroads();
		static void heroMeetGunStore();
		static void enterGunShop();
		static void zedTrade();
		static void buyPistol();
		static void dialogueWithZed();
	//	Klub nocny
	static void nightclub();
		static void nightclubCrossroads();
		static void enterClub();
		static void clubDanceFloor();
		static void clubBar();
		static void miaMeeting();
		static void vincentAssassination();
		static void vincentOffice();
		static void checkVincentDesk();
		static void vincentHideoutCode();
		static void vincentHideout();
		static void dialogueWithVincent();
		static void vincentResurrection();

	// INNE
	//static void showTakeItemInfo(Item findItem); - pomocnicza funkcja do wyœwietlania informacji o zdobyciu przedmiotu
	//static void commands(); - pomocne komendy
	static void heroDeath(); // ekran mierci
	static void loadingFiles(); // ³adowanie plikw
	static void gameOver(); // koniec gry
};
