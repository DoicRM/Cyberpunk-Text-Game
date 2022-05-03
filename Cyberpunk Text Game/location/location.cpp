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

    Location DarkAlley(j["Locations"].value("DarkAlley_Name",""), 0, Fraction::fractions["Beggars"]);
    Location Street(j["Locations"].value("Street_Name", ""), 0, Fraction::fractions["Police"]);
    Location Nightclub(j["Locations"].value("Nightclub_Name", ""), 0, Fraction::fractions["Hammers"]);
    Location GunShop(j["Locations"].value("GunShop_Name", ""), 0, Fraction::fractions["None"]);
    Location SleepersHideout(j["Locations"].value("SleepersHideout_Name", ""), 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}