#include "events.hpp"

bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlley()
{
    Logger::out("Function starts", "Event::darkAlley");

    if (!darkAlleyWasVisited)
    {
        darkAlleyWasVisited = true;
        prologue();
    }
    else
    {
        darkAlleyCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::street()
{
    Logger::out("Function starts", "Event::street");

    if (!streetWasVisited)
    {
        streetWasVisited = true;
        lookAtAmnesia();
    }
    else
    {
        streetCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::gunShop()
{
    Logger::out("Function starts", "Event::gunShop");

    if (!gunShopWasVisited)
    {
        gunShopWasVisited = true;
        encounterGunStore();
    }
    else
    {
        gunShopCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::nightclub()
{
    Logger::out("Function starts", "Event::nightclub");

    if (!nightclubWasVisited)
    {
        nightclubWasVisited = true;
        enterClub();
    }
    else
    {
        Decision::showHeroAction("Visit: Nightclub 'Amnesia'.");
        nightclubCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::sleepersHideout()
{
    Logger::out("Function starts", "Event::sleepersHideout");
    actOne();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Œmieræ bohatera
void Event::heroDeath()
{
    Logger::out("Function starts", "Event::heroDeath");
    clearInstances();
    Sleep(500);
    Console::clearScreen();
    Console::changeConsoleColor(red);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Output::write("\tYOU ARE DEAD!");
    else Output::write("\tNIE ¯YJESZ!");

    Sleep(1000);
    Console::changeConsoleColor();

    if (Game::game[0].getLang() == en) Output::write("\n\n\tBack to menu...", 25);
    else Output::write("\n\n\tWróæ do menu...", 25);

    Console::waitForUserInput();
    Console::clearScreen();
    Game::game[0].logo();
}

// Koniec gry
void Event::gameOver()
{
    Logger::out("Function starts", "Event::gameOver");
    clearInstances();
    Sleep(500);
    Console::clearScreen();
    Console::changeConsoleColor(lightblue);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Output::write("\tTHE END", 25);
    else Output::write("\tKONIEC", 25);

    Sleep(1000);
    std::cout << std::endl << std::endl;
    Console::changeConsoleColor();
    Game::game[0].credits();

    if (Game::game[0].getLang() == en) Output::write("\n\n\tBack to menu...", 25);
    else Output::write("\n\n\tWróæ do menu...", 25);

    Console::waitForUserInput();
    Console::clearScreen();
    Game::game[0].logo();
}

void Event::clearInstances()
{
    Logger::out("Function starts", "Event::clearInstances");
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
}