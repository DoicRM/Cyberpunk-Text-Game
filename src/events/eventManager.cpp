#include "eventManager.hpp"

int heroChoice = 0;
bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

void Event::darkAlley()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!darkAlleyWasVisited)
    {
        darkAlleyWasVisited = true;
        return prologue();
    }

    darkAlleyCrossroads();
}

void Event::street()
{
    Logger::startFuncLog(__FUNCTION__);

    int rand = Randomize::randInt(0, 10);

    if (rand > 5 && rand <= 10)
    {
        RandomEvent::downpourStart();
    }

    if (!streetWasVisited)
    {
        streetWasVisited = true;
        return lookAtAmnesia();
    }

    streetCrossroads();
}

void Event::gunShop()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!gunShopWasVisited)
    {
        gunShopWasVisited = true;
        return encounterGunStore();
    }

    gunShopCrossroads();
}

void Event::nightclub()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!nightclubWasVisited)
    {
        nightclubWasVisited = true;
        return enterClub();
    }

    nightclubCrossroads();
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
    Console::wait(500);
    Console::clearScreen();
    Console::setConsoleColor(ConsoleColor::CC_Red);
    std::cout << std::endl;
    Display::write(jWriter["main"]["youAreDead"]);
    Console::wait(1000);
    Console::setConsoleColor();
    Display::write(jWriter["main"]["backToMenu"], 25);
    Console::waitForUserInput();
    Console::clearScreen();
    Game::game[0].loadLogo();
}

void Event::gameOver()
{
    Logger::startFuncLog(__FUNCTION__);
    clearInstances();
    Console::wait(500);
    Console::clearScreen();
    Console::setConsoleColor(ConsoleColor::CC_Lightblue);
    std::cout << std::endl;
    Display::write(jWriter["main"]["theEnd"], 25);
    Console::wait(1000);
    std::cout << std::endl << std::endl;
    Console::resetConsoleColor();
    Game::game[0].credits();
    Display::write(jWriter["main"]["backToMenu"], 25);
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