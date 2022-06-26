#pragma once
#include "../fraction/fraction.hpp"
#include "../utilities/logger/logger.hpp"
#include <map>

class Location
{
private:
    std::string name;
    Fraction occupation;

public:
    Location();
    Location(std::string name, Fraction occupation);
    virtual ~Location();

    inline void setOccupation(Fraction occupation) { this->occupation = occupation; }
    
    inline const std::string& getName() const { return this->name; };
    inline const Fraction& getOccupation() const { return this->occupation; };

    static std::map <std::string, Location> locations;
    static void initLocations();
};