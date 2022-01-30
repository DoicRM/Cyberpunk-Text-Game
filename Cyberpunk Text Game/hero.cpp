#include "hero.h"

Hero::Hero()
{
    this->name = "None";
    this->hp = 60;
    this->status = "alive";
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
    this->hp = this->hp + hp;
}

void Hero::removeHP(int hp)
{
    this->hp = this->hp - hp;

    if (hp <= 0)
    {
        changeStatus(dead);
    }
}

void Hero::changeStatus(int status)
{
    if (status == alive)
    {
        this->status = "alive";
    }
    else
    {
        this->status = "dead";
        Event::heroDeath();
    }
}

void Hero::addMoney(float money)
{
    this->money = this->money + money;
}

void Hero::delMoney(float money)
{
    if (this->money > 0)
    {
        this->money = this->money - money;
    }
    else
    {
        // You owe a debt to society!
    }
}