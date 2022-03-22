#include "fraction.h"

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitude = neutral;
}

Fraction::Fraction(std::string name, int heroReputation, int attitude)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitude = attitude;
}

Fraction::~Fraction()
{
}

std::string Fraction::printAttitude()
{
    std::string attitude;

    if (this->attitude == angry) attitude = "angry";
    else if (this->attitude == hostile) attitude = "hostile";
    else if (this->attitude == friendly) attitude = "friendly";
    else attitude = "neutral";

    return attitude;
}