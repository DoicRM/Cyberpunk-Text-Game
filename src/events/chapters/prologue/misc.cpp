// ************************************************************
// 		MISC
// ************************************************************

#include "../../events.hpp"

void Event::loadingFiles()
{
    Logger::startFuncLog(__FUNCTION__);
    Console::setConsoleColor(ConsoleColor::CC_Dialogue);
    Display::write("\t||", 100);

    for (int i = 0; i < 21; i++)
    {
        Console::wait(1000);
        Display::write("=", 100);
    }

    Display::write("||", 100);
    Console::wait(1000);
    Display::write(jWriter["main"]["downloadCompleted"]);
    Console::resetConsoleColor();
}

void Event::namingHero()
{
    Logger::startFuncLog(__FUNCTION__);

    std::string heroName;
    Display::writeNarration(jWriter["prologue"]["rememberYourName"]);
    Console::resetConsoleColor();
    heroName = Input::getString();
    Hero::heroes[0].setName(heroName);

    Logger::out("Set <b>" + Hero::heroes[0].getName() + "</b> to hero's name", __FUNCTION__);
}