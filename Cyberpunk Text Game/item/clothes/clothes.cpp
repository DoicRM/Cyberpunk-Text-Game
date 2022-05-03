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

    if (this->type == HEAD) type = j["ClothesTypes"]["Head"];
    else if (this->type == CHEST) type = j["ClothesTypes"]["Chest"];
    else if (this->type == ARMS) type = j["ClothesTypes"]["Arms"];
    else if (this->type == LEGS)  type = j["ClothesTypes"]["Legs"];
    else type = j["ClothesTypes"]["None"];

    return type;
}

void Clothes::initClothes()
{
    Logger::out("Function starts", "Clothes::initClothes");
}
