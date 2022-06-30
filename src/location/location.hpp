#pragma once
#include "../fraction/fraction.hpp"
#include "../utilities/logger/logger.hpp"
#include <map>
#include <functional>

class Location
{
private:
    std::string name;
    Fraction occupation;
    std::function<void()> events;

public:
    Location();
    Location(std::string name, Fraction occupation, std::function<void()> events);
    virtual ~Location();

    inline void setOccupation(Fraction occupation) { this->occupation = occupation; }
    
    inline const std::string& getName() const { return this->name; };
    inline const Fraction& getOccupation() const { return this->occupation; };
    inline const std::function<void()>& getEvents() const { return this->events; };

    static std::map <std::string, Location> locations;
};