#include "events.hpp"

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