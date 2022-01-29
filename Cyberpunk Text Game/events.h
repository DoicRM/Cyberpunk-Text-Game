#pragma once
#include "hero.h"
#include "npc.h"
#include "fraction.h"
#include "item.h"
#include "quest.h"
#include "functions.h"
#include "location.h"

class Event
{
public:
	static void initHero();
	static void initFractionsNpcsAndLocations();
	static void initItems();
	static void initQuests();
	static void initAll();

	// FABULARNE
	static void prologue();
	static void storyIntroduction();
	static void scene001();
	static void scene001_01();
	static void scene001_02();
	static void conversationWithHomeless();
	static void scene002();
	static void heroMeetSecurityGuards();
	static void heroMeetsPolicemans();
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
	static void heroMeetGunStore();
	static void enterGunShop();
	static void ZedTrade();
	static void buyPistol();
	static void dialogueWithZed();
	static void OnStreet();
	static void DarkAlley();

	// INNE
	static void Commands(); // Pomocne komendy
	static void heroDeath(); // Ekran mierci
	static void loadingFiles(); // £adowanie plikw
	static void gameOver(); // Koniec gry
};
