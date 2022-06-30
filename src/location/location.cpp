#include "location.hpp"

std::map <std::string, Location> Location::locations;

Location::Location()
{
    this->name = "None";
    this->occupation = Fraction();
    this->events = nullptr;
}

Location::Location(std::string name, Fraction occupation, std::function<void()> events)
{
    this->name = name;
    this->occupation = occupation;
    this->events = events;
}

Location::~Location()
{
}