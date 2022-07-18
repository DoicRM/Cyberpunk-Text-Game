#pragma once
#include "../Fraction/Fraction.hpp"
#include "../Utilities/Logger/Logger.hpp"
#include <map>
#include <functional>

class Location
{
private:
    std::string name;
    Fraction occupation;
    std::function<void()> events;
    bool isVisited;

public:
    Location();
    Location(std::string name, Fraction occupation, std::function<void()> events);
    virtual ~Location();

    inline void setOccupation(Fraction occupation) { this->occupation = occupation; }
    inline void setIsVisited() { this->isVisited = true; }

    inline const std::string& getName() const { return this->name; }
    inline const Fraction& getOccupation() const { return this->occupation; }
    inline const std::function<void()>& getEvents() const { return this->events; }
    inline const bool& getIsVisited() const { return this->isVisited; }

    static std::map <std::string, Location> locations;
};
