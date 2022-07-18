#include "Location.hpp"

std::map <std::string, Location> Location::locations;

Location::Location()
{
    this->name = "None";
    this->occupation = Fraction();
    this->events = nullptr;
    this->isVisited = false;
}

Location::Location(std::string name, Fraction occupation, std::function<void()> events)
{
    this->name = name;
    this->occupation = occupation;
    this->events = events;
    this->isVisited = false;
}

Location::~Location()
{
}
