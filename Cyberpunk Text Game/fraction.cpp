#include "fraction.h"

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitudeToHero = "neutral";
}

Fraction::Fraction(string name, int heroReputation, string attitudeToHero)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitudeToHero = attitudeToHero;
}

Fraction::~Fraction()
{

}