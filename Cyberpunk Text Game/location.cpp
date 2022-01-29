#include "location.h"

Location::Location()
{
    this->name = "None";
    this->type = 0;
    this->order = 0;
    this->owner = Fraction();
    this->currency = 0;
}

Location::Location(string name, int type, int order, Fraction owner, bool currency)
{
    this->name = name;
    this->type = type;
    this->order = order;
    this->owner = owner;
    this->currency = currency;
}

Location::~Location()
{
}

void Location::setOwner(Fraction owner)
{
    this->owner = owner;
}