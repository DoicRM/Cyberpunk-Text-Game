// ************************************************************
// 		SLEEPERS HIDEOUT in Paradise Lost
// ************************************************************

#include "ChapterOne.hpp"

void Event::chapterOne()
{
    Logger::startFuncLog(__FUNCTION__);

    Display::write(json["chapterOne"]["title"]);
    Console::wait(2000);
    Display::write(json["chapterOne"]["subtitle"]);
    Console::wait(5000);
    Console::clearScreen();
}

void Event::sleepersHideoutCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    // TODO
}