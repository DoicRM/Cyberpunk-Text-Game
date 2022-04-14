#include "clothes.hpp"

Clothes::Clothes() : Item()
{
    this->clothesType = -1;
    this->defence = 0;
}

Clothes::Clothes(std::string name, int type, int clothesType, std::string description, int defence, float price)
{
    this->clothesType = clothesType;
    this->defence = defence;
}

Clothes::~Clothes()
{
}

std::string Clothes::printClothesType()
{
    std::string type;

    if (this->type == HEAD) type = "Head";
    else if (this->type == CHEST) type = "Chest";
    else if (this->type == ARMS) type = "Arms";
    else if (this->type == LEGS)  type = "Legs";
    else type = "None";

    return type;
}

void Clothes::initClothes_EN()
{
    Logger::out("Function starts", "Clothes::initClothes_EN");
}

void Clothes::initClothes_PL()
{
    Logger::out("Function starts", "Clothes::initClothes_PL");
}