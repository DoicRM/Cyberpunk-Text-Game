#include "fraction.h"

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitude = neutral;
}

Fraction::Fraction(string name, int heroReputation, int attitude)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitude = attitude;
}

Fraction::~Fraction()
{
}

void Fraction::addRep(int rep)
{
    this->heroReputation += rep;
}

void Fraction::removeRep(int rep)
{
    this->heroReputation -= rep;
}

void Fraction::setAttitude(int attitude)
{
    this->attitude = attitude;
}

string Fraction::printAttitude()
{
    string attitude;

    if (this->attitude == angry)
    {
        attitude = "angry";
    }
    else if (this->attitude == hostile)
    {
        attitude = "hostile";
    }
    else if (this->attitude == friendly)
    {
        attitude = "friendly";
    }
    else
    {
        attitude = "neutral";
    }

    return attitude;
}