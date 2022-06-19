#include "location.hpp"

std::map <std::string, Location> Location::locations;

Location::Location()
{
    this->name = "None";
    this->type = 0;
    this->occupation = Fraction();
}

Location::Location(std::string name, int type, Fraction occupation)
{
    this->name = name;
    this->type = type;
    this->occupation = occupation;
}

Location::~Location()
{
}

void Location::initLocations()
{
    Logger::startFuncLog(__FUNCTION__);

    Location DarkAlley(jWriter["locations"]["darkAlley"]["name"], 0, Fraction::fractions["Beggars"]);
    Location Street(jWriter["locations"]["street"]["name"], 0, Fraction::fractions["Police"]);
    Location Nightclub(jWriter["locations"]["nightclub"]["name"], 0, Fraction::fractions["Hammers"]);
    Location GunShop(jWriter["locations"]["gunShop"]["name"], 0, Fraction::fractions["None"]);
    Location SleepersHideout(jWriter["locations"]["sleepersHideout"]["name"], 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}