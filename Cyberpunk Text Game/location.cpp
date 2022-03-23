#include "location.h"

std::map <std::string, Location> Location::locations;

Location::Location()
{
    this->name = "None";
    this->type = 0;
    this->occupation = Fraction();
    this->order = 0;
    this->currency = 0;
}

Location::Location(std::string name, int type, Fraction occupation, int order, bool currency)
{
    this->name = name;
    this->type = type;
    this->order = order;
    this->occupation = occupation;
    this->currency = currency;
}

Location::~Location()
{
}

void Location::initLocations()
{
    Logger::out("Function start", "Location::initLocations");

    Location DarkAlley("Dark alley", 0, Fraction::fractions["Beggars"], 1, false);
    Location Street("Street", 0, Fraction::fractions["Police"], 2, false);
    Location Nightclub("Nightclub 'Amnesia'", 0, Fraction::fractions["Hammers"], 3, false);
    Location GunShop("Zed's Gun Shop", 0, Fraction::fractions["None"], 3, false);

    locations["DarkAlley"] = DarkAlley;
    locations["Street"] = Street;
    locations["Nightclub"] = Nightclub;
    locations["GunShop"] = GunShop;
}