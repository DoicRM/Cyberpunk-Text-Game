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

void Location::initLocations_EN()
{
    Logger::out("Function starts", "Location::initLocations_EN");

    Location DarkAlley("Dark alley", 0, Fraction::fractions["Beggars"]);
    Location Street("Street", 0, Fraction::fractions["Police"]);
    Location Nightclub("Nightclub 'Amnesia'", 0, Fraction::fractions["Hammers"]);
    Location GunShop("Zed's Gun Shop", 0, Fraction::fractions["None"]);
    Location SleepersHideout("Sleepers Hideout", 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}

void Location::initLocations_PL()
{
    Logger::out("Function starts", "Location::initLocations_PL");

    Location DarkAlley("Mroczny zau³ek", 0, Fraction::fractions["Beggars"]);
    Location Street("Ulica", 0, Fraction::fractions["Police"]);
    Location Nightclub("Klub nocny 'Amnezja'", 0, Fraction::fractions["Hammers"]);
    Location GunShop("Sklep z broni¹ 'U Zeda'", 0, Fraction::fractions["None"]);
    Location SleepersHideout("Kryjówka Œni¹cych", 0, Fraction::fractions["Sleepers"]);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
    locations["SleepersHideout"] = SleepersHideout;
}