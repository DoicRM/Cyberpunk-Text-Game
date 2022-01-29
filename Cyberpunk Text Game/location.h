#pragma once
#include "fraction.h"

class Location
{
    string name;
    int type;
    int order;
    Fraction owner;
    bool currency;

public:
    Location();
    Location(string name, int type, int order, Fraction owner, bool currency);
    virtual ~Location();

    inline const string& getName() const { return this->name; };
    inline const int& getType() const { return this->type; };
    inline const Fraction& getOwner() const { return this->owner; };
    inline const bool& isCurrent() const { return this->currency; };

    void setOwner(Fraction owner);
    //void SetNeighbors(string north, string south, string east, string west);
};