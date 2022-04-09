#pragma once
#include <map>
#include "fraction.h"
#include "logger.h"

class Location
{
private:
    std::string name;
    int type;
    Fraction occupation;
    int order;
    bool currency;

public:
    Location();
    Location(std::string name, int type, Fraction occupation, int order, bool currency);
    virtual ~Location();

    inline void setOccupation(Fraction occupation) { this->occupation = occupation; }

    inline const std::string& getName() const { return this->name; };
    inline const int& getType() const { return this->type; };
    inline const Fraction& getOccupation() const { return this->occupation; };
    inline const bool& isCurrent() const { return this->currency; };

    static std::map <std::string, Location> locations;
    static void initLocations_EN();
    static void initLocations_PL();
};