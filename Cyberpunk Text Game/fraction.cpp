#include "fraction.h"

Fraction::Fraction()
{
    this->name = "None";
    this->leader = Npc();
    this->heroReputation = 0;
    this->attitudeToHero = "neutral";
}

Fraction::Fraction(string name, int heroReputation, string attitudeToHero)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitudeToHero = attitudeToHero;
}

Fraction::Fraction(string name, Npc leader, int heroReputation, string attitudeToHero)
{
    this->name = name;
    this->leader = leader;
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

void Fraction::removeRep(int rep)
{
    this->heroReputation -= rep;
}

void Fraction::setLeader(Npc leader)
{
    this->leader = leader;
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