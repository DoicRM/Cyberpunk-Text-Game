#include "npc.h"

Npc::Npc()
{
    this->name = "None";
    this->fraction = Fraction();
    this->attitude = "neutral";
    this->status = "alive";
    this->knowsHero = false;
}

Npc::Npc(string name, Fraction fraction)
{
    this->name = name;
    this->fraction = fraction;
    this->attitude = "neutral";
    this->status = "alive";
    this->knowsHero = false;
}


Npc::Npc(string name, Fraction fraction, string attitude, string status, bool knowsHero)
{
    this->name = name;
    this->fraction = fraction;
    this->attitude = attitude;
    this->status = status;
    this->knowsHero = knowsHero;
}

Npc::~Npc()
{

}

void Npc::setAttitude(int attitude)
{
    if (attitude == angry)
    {
        this->attitude = "angry";
        Function::changeConsoleColor(yellow);
    }
    else if (attitude == hostile)
    {
        this->attitude = "hostile";
        Function::changeConsoleColor(red);
    }
    else if (attitude == friendly)
    {
        this->attitude = "friendly";
        Function::changeConsoleColor(green);
    }
    else
    {
        this->attitude = "neutral";
        Function::changeConsoleColor();
    }

    string str = "  " + this->name + " is " + this->attitude + " now.";
    Function::write(str);
    cout << endl;
    Function::changeConsoleColor();
}

void Npc::setStatus(int status)
{
    if (status == alive)
    {
        this->status = "alive";
    }
    else if (status == dead)
    {
        this->status = "dead";
    }
}

bool Npc::isDead()
{
    if (status == "alive") return false;
    else return true;
}

void Npc::setToKnowHero()
{
    knowsHero = true;
}

bool Npc::isKnowsHero()
{
    return knowsHero;
}