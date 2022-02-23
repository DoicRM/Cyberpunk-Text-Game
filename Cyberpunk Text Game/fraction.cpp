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

void Fraction::addRep(int rep)
{
    this->heroReputation += rep;
}

void Fraction::delRep(int rep)
{
    this->heroReputation -= rep;
}

void Fraction::setAttitude(int attitude)
{
    if (attitude == angry)
    {
        this->attitudeToHero = "angry";
        //Function::changeConsoleColor(yellow);
    }
    else if (attitude == hostile)
    {
        this->attitudeToHero = "hostile";
        //Function::changeConsoleColor(red);
    }
    else if (attitude == friendly)
    {
        this->attitudeToHero = "friendly";
        //Function::changeConsoleColor(green);
    }
    else
    {
        this->attitudeToHero = "neutral";
        //Function::changeConsoleColor();
    }
}