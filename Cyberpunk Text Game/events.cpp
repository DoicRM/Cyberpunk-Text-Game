#include "events.h"

bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlley()
{
    Logger::out("Function start", "Event::darkAlley");

    if (!darkAlleyWasVisited)
    {
        //darkAlleyWasVisited = true;
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
    Logger::out("Function start", "Event::street");

    if (!streetWasVisited)
    {
        //streetWasVisited = true;
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
    Logger::out("Function start", "Event::gunShop");

    if (!gunShopWasVisited)
    {
        //gunShopWasVisited = true;
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
    Logger::out("Function start", "Event::nightclub");

    if (!nightclubWasVisited)
    {
        //nightclubWasVisited = true;
        Function::showHeroAction("Go inside.");
        enterClub();
    }
    else
    {
        Function::showHeroAction("Visit: Nightclub 'Amnesia'.");
        nightclubCrossroads();
    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Œmieræ bohatera
void Event::heroDeath()
{
    Logger::out("Function start", "Event::heroDeath");
    clearInstances();
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(red);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tYOU ARE DEAD!");
    else if (Game::game[0].getLang() == pl) Function::write("\tNIE ¯YJESZ!");

    Sleep(1000);
    std::cout << std::endl << std::endl;
    Function::changeConsoleColor();

    if (Game::game[0].getLang() == en) Function::write("\tBack to menu...", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game::game[0].logo();
}

// Koniec gry
void Event::gameOver()
{
    Logger::out("Function start", "Event::gameOver");
    clearInstances();
    Sleep(500);
    Function::clearScreen();
    Function::changeConsoleColor(lightblue);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tTHE END", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tKONIEC", 25);

    Sleep(1000);
    std::cout << std::endl << std::endl;
    Function::changeConsoleColor();
    Game::game[0].credits();
    std::cout << std::endl << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tBack to menu...", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Function::clearScreen();
    Game::game[0].logo();
}

void Event::clearInstances()
{
    Logger::out("Function start", "Event::clearInstances");
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
}