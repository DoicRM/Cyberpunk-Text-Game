#include "location.hpp"

std::map <std::string, Location> Location::locations;

Location::Location()
{
    this->name = "None";
    this->occupation = Fraction();
}

Location::Location(std::string name, Fraction occupation)
{
    this->name = name;
    this->occupation = occupation;
}

Location::~Location()
{
}

void Location::initLocations()
{
    Logger::startFuncLog(__FUNCTION__);

    Location DarkAlley(jWriter["locations"]["darkAlley"]["name"], Fraction::fractions["Beggars"]);
    Location Street(jWriter["locations"]["street"]["name"], Fraction::fractions["Police"]);
    Location Nightclub(jWriter["locations"]["nightclub"]["name"], Fraction::fractions["Hammers"]);
    Location GunShop(jWriter["locations"]["gunShop"]["name"], Fraction::fractions["None"]);
    Location SleepersHideout(jWriter["locations"]["sleepersHideout"]["name"], Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}