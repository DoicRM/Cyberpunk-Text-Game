// ************************************************************
// 		PROLOGUE - Paradise Lost
// ************************************************************

#include "Prologue.hpp"

void Event::darkAlley()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Location::locations["DarkAlley"].getIsVisited())
    {
        Location::locations["DarkAlley"].setIsVisited();
        return prologue();
    }

    darkAlleyCrossroads();
}

void Event::street()
{
    Logger::startFuncLog(__FUNCTION__);

    if (Game::game[0].getWeather() != Weather::Rainy)
    {
        int rand = Utilities::randInt(0, 10);

        if (rand > 5 && rand <= 10)
        {
            RandomEvent::downpourStart();
        }
    }

    if (!Location::locations["Street"].getIsVisited())
    {
        Location::locations["Street"].setIsVisited();
        return lookAtEden();
    }

    streetCrossroads();
}

void Event::gunShop()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Location::locations["GunShop"].getIsVisited())
    {
        Location::locations["GunShop"].setIsVisited();
        return encounterGunStore();
    }

    gunShopCrossroads();
}

void Event::nightclub()
{
    Logger::startFuncLog(__FUNCTION__);

    if (!Location::locations["GunShop"].getIsVisited())
    {
        Location::locations["GunShop"].setIsVisited();
        return enterClub();
    }

    nightclubCrossroads();
}

void Event::visitDarkAlley()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["DarkAlley"]);
}

void Event::visitStreet()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["Street"]);
}

void Event::visitNightclub()
{
    Logger::startFuncLog(__FUNCTION__);
    Display::writeNarration("\n\tYou enter from a fairly well-lit street into a slightly darkened nightclub, trembling with colour.\n\n");
    Game::game[0].setCurrentLocation(&Location::locations["Nightclub"]);
}

void Event::visitGunShop()
{
    Logger::startFuncLog(__FUNCTION__);
    Game::game[0].setCurrentLocation(&Location::locations["GunShop"]);
}