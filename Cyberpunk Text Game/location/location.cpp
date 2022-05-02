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
    Logger::out("Function starts", "Location::initLocations");

    Location DarkAlley(JSON::getValue("Location_DarkAlley_Name"), 0, Fraction::fractions["Beggars"]);
    Location Street(JSON::getValue("Location_Street_Name"), 0, Fraction::fractions["Police"]);
    Location Nightclub(JSON::getValue("Location_Nightclub_Name"), 0, Fraction::fractions["Hammers"]);
    Location GunShop(JSON::getValue("Location_GunShop_Name"), 0, Fraction::fractions["None"]);
    Location SleepersHideout(JSON::getValue("Location_SleepersHideout_Name"), 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}