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

    if (this->type == HEAD) type = jWriter["ClothesTypes"]["Head"];
    else if (this->type == CHEST) type = jWriter["ClothesTypes"]["Chest"];
    else if (this->type == ARMS) type = jWriter["ClothesTypes"]["Arms"];
    else if (this->type == LEGS)  type = jWriter["ClothesTypes"]["Legs"];
    else type = jWriter["ClothesTypes"]["None"];

    return type;
}

void Clothes::initClothes()
{
    Logger::out("Function starts", "Clothes::initClothes");
}
