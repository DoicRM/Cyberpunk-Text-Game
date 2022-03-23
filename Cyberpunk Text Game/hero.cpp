#include "hero.h"

std::map <std::string, Hero> Hero::heroes;

Hero::Hero()
{
    this->name = "None";
    this->sex = undefined;
    this->hp = 60;
    this->money = 0.0;
}

Hero::~Hero()
{
}

void Hero::removeHP(int hp)
{
    this->hp -= hp;

    if (hp <= 0) kill();
}

void Hero::kill()
{
    Event::heroDeath();
};

void Hero::removeMoney(float money)
{
    if (this->money > 0)
    {
        this->money -= money;
    }
}

void Hero::initHero()
{
    Logger::out("Function start", "Hero::initHero");

    Hero hero;
    heroes["Hero"] = hero;
}