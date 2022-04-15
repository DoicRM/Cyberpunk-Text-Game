#include "hero.hpp"

std::map <int, Hero> Hero::heroes;

Hero::Hero()
{
    this->name = "None";
    this->sex = Undefined;
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

void Hero::initHero()
{
    Logger::out("Function starts", "Hero::initHero");

    Hero hero;
    heroes[0] = hero;
}