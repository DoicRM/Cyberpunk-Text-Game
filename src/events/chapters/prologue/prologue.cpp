// ************************************************************
// 		PROLOGUE - Paradise Lost
// ************************************************************

#include "prologue.hpp"

bool darkAlleyWasVisited = false,
     streetWasVisited    = false,
     gunShopWasVisited   = false,
     nightclubWasVisited = false,
     isRaining           = false;

void Event::darkAlley()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!darkAlleyWasVisited)
    {
        darkAlleyWasVisited = true;
        return prologue();
    }

    darkAlleyCrossroads();
}

void Event::street()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!isRaining)
    {
        int rand = Randomize::randInt(0, 10);

        if (rand > 5 && rand <= 10)
        {
            RandomEvent::downpourStart();
            isRaining = true;
        }
    }

    if (!streetWasVisited)
    {
        streetWasVisited = true;
        return lookAtEden();
    }

    streetCrossroads();
}

void Event::gunShop()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!gunShopWasVisited)
    {
        gunShopWasVisited = true;
        return encounterGunStore();
    }

    gunShopCrossroads();
}

void Event::nightclub()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!nightclubWasVisited)
    {
        nightclubWasVisited = true;
        return enterClub();
    }

    nightclubCrossroads();
}