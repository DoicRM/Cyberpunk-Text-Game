#include "../events.hpp"

void Event::actOne()
{
    Logger::startFuncLog(__FUNCTION__);

    if (Game::game[0].getLang() == EN)
    {
        Display::write("\n\tChapter One");
    }
    else {
        Display::write("\n\tRozdzia� pierwszy");
    }

    Console::wait(2000);

    if (Game::game[0].getLang() == EN) {
        Display::write("\n\n\tPROSELYTISM");
    }
    else {
        Display::write("\n\n\tNAWR�CENIE");
    }

    Console::wait(5000);
    Console::clearScreen();
}

// KRYJ�WKA �NI�CYCH
void Event::sleepersHideoutCrossroads()
{
    Logger::startFuncLog(__FUNCTION__);
    // TODO
}