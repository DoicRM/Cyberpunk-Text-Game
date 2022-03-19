#include "npc.h"

Npc::Npc()
{
    this->name = "None";
    this->fraction = Fraction();
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, Fraction fraction)
{
    this->name = name;
    this->fraction = fraction;
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}


Npc::Npc(std::string name, Fraction fraction, int attitude, int status, bool knowingHero)
{
    this->name = name;
    this->fraction = fraction;
    this->attitude = attitude;
    this->status = status;
    this->knowingHero = knowingHero;
}

Npc::~Npc()
{
}

void Npc::setAttitude(int attitude)
{
    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == angry)
    {
        attitude = "angry";
        Function::changeConsoleColor(yellow);
    }
    else if (this->attitude == hostile)
    {
        attitude = "hostile";
        Function::changeConsoleColor(red);
    }
    else if (this->attitude == friendly)
    {
        attitude = "friendly";
        Function::changeConsoleColor(green);
    }
    else
    {
        attitude = "neutral";
        Function::changeConsoleColor();
    }

    std::string str = "\t" + this->name + " is " + attitude + " now.";
    Function::write(str);
    std::cout << std::endl;
    Function::changeConsoleColor();
}

void Npc::setStatus(int status)
{
    this->status = status;
}

bool Npc::isDead()
{
    if (status != dead) return false;
    return true;
}

void Npc::setToKnowHero()
{
    knowingHero = true;
}

bool Npc::knowsHero()
{
    return knowingHero;
}