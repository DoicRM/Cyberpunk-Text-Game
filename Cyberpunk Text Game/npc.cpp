#include "npc.h"

Npc::Npc()
{
    this->name = "None";
    this->sex = undefined;
    this->fraction = Fraction();
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, int sex, Fraction fraction)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = neutral;
    this->status = normal;
    this->knowingHero = false;
}


Npc::Npc(std::string name, int sex, Fraction fraction, int attitude, int status, bool knowingHero)
{
    this->name = name;
    this->sex = sex;
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

bool Npc::isDead()
{
    if (status != dead) return false;
    return true;
}