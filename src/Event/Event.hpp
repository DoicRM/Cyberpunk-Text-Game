#pragma once
#include "../Game/Game.hpp"
#include <map>

class Event
{
public:
	// PROLOGUE
	static void darkAlley();
	static void street();
	static void gunShop();
	static void nightclub();
	// CHAPTER ONE
	static void sleepersHideout();
	// MISC
	static void heroDeath();
	static void loadingFiles();
	static void gameOver();
	static void clearInstances();
	static void namingHero();

private:
	// PROLOGUE
	// Dark Alley
	static void prologue();
	static void storyIntroduction();
	static void wakeUpInDarkAlley();
	static void acceleratorFinding();
	static void rubbishSearch();
	static void outOfAlley();
	static void outOfAlley_1();
	static void outOfAlley_2();
	static void dialogueWithBob();
	static void dialogueWithBob_1();
	static void dialogueWithBob_2();
	static void aboutParadiseLost();
	static void aboutParadiseLost_1();
	static void aboutParadiseLost_2();
	static void dialogueWithBob_3();
	static void dialogueWithBob_4();
	static void dialogueWithBob_5();
	static void darkAlleyCrossroads();
	static void darkAlleyCrossroads_1();
	static void darkAlleyCrossroads_2();
	// Street 
	static void lookAtEden();
	static void lookAtEden_1();
	static void lookAtEden_2();
	static void meetingWithSecurityGuards();
	static void meetingWithPolicemans();
	static void meetingWithPolicemans_1();
	static void meetingWithPolicemans_2();
	static void wakeUpBeforeMeetingWithJet();
	static void streetCrossroads();
	static void visitDarkAlley();
	static void visitStreet();
	static void visitNightclub();
	static void visitGunShop();
	// Zed's Gun Shop
	static void encounterGunStore();
	static void encounterGunStore_1();
	static void enterGunShop();
	static void zedTrade();
	static void zedTrade_1();
	static void buyPistol();
	static void dialogueWithZed();
	static void dialogueWithZed_1();
	static void dialogueWithZed_2();
	static void dialogueWithZed_3();
	static void dialogueWithZed_4();
	static void dialogueWithZed_5();
	static void zedGetsAnAccelerator();
	static void gunShopCrossroads();
	// Nightclub 'Eden'
	static void enterClub();
	static void clubDanceFloor();
	static void clubDanceFloor_1();
	static void clubDanceFloor_2();
	static void clubDanceFloor_3();
	static void clubBar();
	static void clubBar_1();
	static void clubBar_2();
	static void clubBar_3();
	static void miaMeeting();
	static void miaMeeting_1();
	static void miaMeeting_2();
	static void clubUpstairs();
	static void clubUpstairs_1();
	static void clubUpstairs_2();
	static void dialogueWithJet();
	static void dialogueWithJet_1();
	static void dialogueWithJet_2();
	static void dialogueWithJet_3();
	static void dialogueWithJet_4();
	static void dialogueWithJet_5();
	static void jetGetsAngry(int angerPoints);
	static void vincentOffice();
	static void checkVincentDesk();
	static void vincentHideoutCode();
	static void vincentHideout();
	static void vincentHideout_1();
	static void vincentHideout_2();
	static void dialogueWithVincent();
	static void dialogueWithVincent_1();
	static void dialogueWithVincent_2();
	static void dialogueWithVincent_3();
	static void dialogueWithVincent_4();
	static void dialogueWithVincent_5();
	static void dialogueWithVincent_6();
	static void dialogueWithVincent_7();
	static void vincentDeath();
	static void vincentResurrection();
	static void nightclubCrossroads();
	// CHAPTER ONE
	// Sleepers Hideout
	static void chapterOne();
	static void sleepersHideoutCrossroads();
};

class RandomEvent : Event {
public:
	static void downpourStart();
	static void nickHandFinding();
	static void hookersMeeting();
	static void punksMeeting();
	static void clubOverdose();
};