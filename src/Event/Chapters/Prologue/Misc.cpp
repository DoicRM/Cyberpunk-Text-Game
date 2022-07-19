// ************************************************************
// 		MISC
// ************************************************************

#include "Prologue.hpp"

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
    Display::write(json["main"]["downloadCompleted"]);
    Console::resetConsoleColor();
}

void Event::namingHero()
{
    Logger::startFuncLog(__FUNCTION__);

    std::string heroName;
    Display::writeNarration(json["prologue"]["rememberYourName"]);
    Console::resetConsoleColor();
    heroName = Input::getString();
    Npc::npcs["Hero"].setName(heroName);
    SaveManager::updateSave(0, heroName, Sex::Undefined, 0, 1);

    Logger::out("Set <b>" + Npc::npcs["Hero"].getName() + "</b> to hero's name", __FUNCTION__);
}
