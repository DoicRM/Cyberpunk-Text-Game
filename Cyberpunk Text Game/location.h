#pragma once
#include "fraction.h"

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

    void setOccupation(Fraction occupation) { this->occupation = occupation; }
    //void SetNeighbors(string north, string south, string east, string west);

    inline const std::string& getName() const { return this->name; };
    inline const int& getType() const { return this->type; };
    inline const Fraction& getOccupation() const { return this->occupation; };
    inline const bool& isCurrent() const { return this->currency; };
};