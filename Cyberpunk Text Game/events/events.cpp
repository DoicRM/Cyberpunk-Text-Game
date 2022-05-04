#include "events.hpp"

int heroChoice = 0;
bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

void Event::darkAlley()
{
    Logger::startFuncLog(__FUNCTION__);

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

void Event::street()
{
    Logger::startFuncLog(__FUNCTION__);

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

void Event::gunShop()
{
    Logger::startFuncLog(__FUNCTION__);

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

void Event::nightclub()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!nightclubWasVisited)
    {
        nightclubWasVisited = true;
        enterClub();
    }
    else
    {
        nightclubCrossroads();
    }
}

void Event::sleepersHideout()
{
    Logger::startFuncLog(__FUNCTION__);
    actOne();
}

void Event::heroDeath()
{
    Logger::startFuncLog(__FUNCTION__);
    clearInstances();
    Sleep(500);
    Console::clearScreen();
    Console::setConsoleColor(CC_Red);
    std::cout << std::endl;

    if (Game::game[0].getLang() == EN) Display::write("\tYOU ARE DEAD!");
    else Display::write("\tNIE ¯YJESZ!");

    Sleep(1000);
    Console::setConsoleColor();

    if (Game::game[0].getLang() == EN) Display::write("\n\n\tBack to menu...", 25);
    else Display::write("\n\n\tWróæ do menu...", 25);

    Console::waitForUserInput();
    Console::clearScreen();
    Game::game[0].loadLogo();
}

void Event::gameOver()
{
    Logger::startFuncLog(__FUNCTION__);
    clearInstances();
    Sleep(500);
    Console::clearScreen();
    Console::setConsoleColor(CC_Lightblue);
    std::cout << std::endl;

    if (Game::game[0].getLang() == EN) Display::write("\tTHE END", 25);
    else Display::write("\tKONIEC", 25);

    Sleep(1000);
    std::cout << std::endl << std::endl;
    Console::resetConsoleColor();
    Game::game[0].credits();

    if (Game::game[0].getLang() == EN) Display::write("\n\n\tBack to menu...", 25);
    else Display::write("\n\n\tWróæ do menu...", 25);

    Console::waitForUserInput();
    Console::clearScreen();
    Game::game[0].loadLogo();
}

void Event::clearInstances()
{
    Logger::startFuncLog(__FUNCTION__);
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
}