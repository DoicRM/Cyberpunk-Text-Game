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
	static void DarkAlley();
		static void DarkAlleyCrossroads();
		static void prologue();
		static void storyIntroduction();
		static void wakeUpAloneInDarkAlley();
		static void inSeaOfRubbish();
		static void outOfTheAlley();
		static void conversationWithHomeless();
	//	Ulica
	static void Street();
		static void StreetCrossroads();
		static void viewOfAmnesia();
		static void heroMeetSecurityGuards();
		static void heroMeetsPolicemans();
	//	Sklep z broni¹
	static void GunShop();
		static void GunShopCrossroads();
		static void heroMeetGunStore();
		static void enterGunShop();
		static void ZedTrade();
		static void buyPistol();
		static void dialogueWithZed();
	//	Klub nocny
	static void Nightclub();
		static void NightclubCrossroads();
		static void enterClub();
		static void clubDanceFloor();
		static void clubBar();
		static void MiaMeeting();
		static void VincentAssassination();
		static void VincentOffice();
		static void checkVincentDesk();
		static void VincentHideoutCode();
		static void VincentHideout();
		static void dialogueWithVincent();
		static void VincentResurrection();

	// INNE
	//static void showTakeItemInfo(Item findItem); Pomocnicza funkcja do wyœwietlania informacji o zdobyciu przedmiotu
	static void Commands(); // Pomocne komendy
	static void heroDeath(); // Ekran mierci
	static void loadingFiles(); // £adowanie plikw
	static void gameOver(); // Koniec gry
};
