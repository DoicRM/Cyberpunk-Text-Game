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

    Location DarkAlley(jWriter.at("Locations").value("DarkAlley_Name", JSON_VALUE_ERROR), 0, Fraction::fractions["Beggars"]);
    Location Street(jWriter.at("Locations").value("Street_Name", JSON_VALUE_ERROR), 0, Fraction::fractions["Police"]);
    Location Nightclub(jWriter.at("Locations").value("Nightclub_Name", JSON_VALUE_ERROR), 0, Fraction::fractions["Hammers"]);
    Location GunShop(jWriter.at("Locations").value("GunShop_Name", JSON_VALUE_ERROR), 0, Fraction::fractions["None"]);
    Location SleepersHideout(jWriter.at("Locations").value("SleepersHideout_Name", JSON_VALUE_ERROR), 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}