#include "Hero.hpp"

std::map<std::string, Hero> Hero::heroes;

Hero::Hero() : Npc()
{
    this->hp = 60;
    this->money = 0.0;
}

Hero::~Hero()
{
}

void Hero::removeHP(int hp)
{
    this->hp -= hp;

    if (hp <= 0)
    {
        kill();
    }
}

void Hero::kill()
{
    Event::heroDeath();
};

void Hero::initHero()
{
    Logger::startFuncLog(__FUNCTION__);
    Hero hero;
    heroes["Hero"] = hero;
}