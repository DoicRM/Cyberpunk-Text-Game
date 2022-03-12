#include "hero.h"

Hero::Hero()
{
    this->name = "None";
    this->hp = 60;
    this->money = 0.0;
}

Hero::~Hero()
{

}

void Hero::setName(string name)
{
    this->name = name;
}

void Hero::addHP(int hp)
{
    this->hp += hp;
}

void Hero::removeHP(int hp)
{
    this->hp -= hp;

    if (hp < 0) kill();
}

void Hero::kill()
{
    this->hp = -1;
    Event::heroDeath();
}

void Hero::addMoney(float money)
{
    this->money += money;
}

void Hero::removeMoney(float money)
{
    if (this->money > 0)
    {
        this->money -= money;
    }
    /*
    else
    {
        You owe a debt to society!
    }
    */
}