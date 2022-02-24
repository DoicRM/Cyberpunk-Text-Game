#include "location.h"

Location::Location()
{
    this->name = "None";
    this->type = 0;
    this->occupation = Fraction();
    this->order = 0;
    this->currency = 0;
}

Location::Location(string name, int type, Fraction occupation, int order, bool currency)
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

void Location::setOccupation(Fraction occupation)
{
    this->occupation = occupation;
}