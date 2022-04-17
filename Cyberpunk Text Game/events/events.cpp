#include "events.hpp"

bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

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
        nightclubCrossroads();
    }
}

void Event::sleepersHideout()
{
    Logger::out("Function starts", "Event::sleepersHideout");
    actOne();
}

void Event::heroDeath()
{
    Logger::out("Function starts", "Event::heroDeath");
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
    Logger::out("Function starts", "Event::gameOver");
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
    Logger::out("Function starts", "Event::clearInstances");
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
}