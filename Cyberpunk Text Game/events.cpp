#include "events.h"

Location* locationPtr;
bool darkAlleyWasVisited = false, streetWasVisited = false, gunShopWasVisited = false, nightclubWasVisited = false;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Event::darkAlley()
{
    Logger::out("Function start", "Event::darkAlley");
    locationPtr = &Location::locations["DarkAlley"];
    Game::game[0].setCurrentLocation(locationPtr);

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
    locationPtr = &Location::locations["Street"];
    Game::game[0].setCurrentLocation(locationPtr);

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
    locationPtr = &Location::locations["GunShop"];
    Game::game[0].setCurrentLocation(locationPtr);

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
    locationPtr = &Location::locations["Nightclub"];
    Game::game[0].setCurrentLocation(locationPtr);

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
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
    Sleep(500);
    Game::clearScreen();
    Function::changeConsoleColor(red);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tYOU ARE DEAD!");
    else if (Game::game[0].getLang() == pl) Function::write("\tNIE ¯YJESZ!");

    Sleep(1000);
    std::cout << std::endl;
    std::cout << "" << std::endl;
    Function::changeConsoleColor();

    if (Game::game[0].getLang() == en) Function::write("\tBack to menu...", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Game::clearScreen();
    Game().logo();
}

// Koniec gry
void Event::gameOver()
{
    Logger::out("Function start", "Event::gameOver");
    Hero::heroes.clear();
    Npc::npcs.clear();
    Fraction::fractions.clear();
    Item::items.clear();
    Location::locations.clear();
    Quest::quests.clear();
    Sleep(500);
    Game::clearScreen();
    Function::changeConsoleColor(lightblue);
    std::cout << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tTHE END", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tKONIEC", 25);

    Sleep(1000);
    std::cout << std::endl << std::endl;
    Function::changeConsoleColor();
    Game().credits();
    std::cout << std::endl << std::endl;

    if (Game::game[0].getLang() == en) Function::write("\tBack to menu...", 25);
    else if (Game::game[0].getLang() == pl) Function::write("\tWróæ do menu...", 25);

    Function::waitForUserInput();
    Game::clearScreen();
    Game().logo();
}