#include "../events.hpp"

void Event::actOne()
{
    Logger::startFuncLog(__FUNCTION__);

    if (Game::game[0].getLang() == EN)
    {
        Display::write("\n\tAct One");
    }
    else {
        Display::write("\n\tAkt pierwszy");
    }

    Console::wait(2000);

    if (Game::game[0].getLang() == EN) {
        Display::write("\n\n\tPROSELYTISM");
    }
    else {
        Display::write("\n\n\tNAWRÓCENIE");
    }

    Console::wait(5000);
    Console::clearScreen();
}

// KRYJÓWKA ŒNI¥CYCH
void Event::sleepersHideoutCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    // TODO
}