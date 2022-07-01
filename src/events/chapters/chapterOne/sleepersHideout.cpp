// ************************************************************
// 		SLEEPERS HIDEOUT in Paradise Lost
// ************************************************************

#include "chapterOne.hpp"

void Event::chapterOne()
{
    Logger::startFuncLog(__FUNCTION__);

    Display::write(jWriter["chapterOne"]["title"]);
    Console::wait(2000);
    Display::write(jWriter["chapterOne"]["subtitle"]);
    Console::wait(5000);
    Console::clearScreen();
}

void Event::sleepersHideoutCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    // TODO
}