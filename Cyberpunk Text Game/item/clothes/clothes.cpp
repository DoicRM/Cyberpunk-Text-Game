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

    if (this->type == HEAD) type = JSON::getValue("ClothesType_Head");
    else if (this->type == CHEST) type = JSON::getValue("ClothesType_Chest");
    else if (this->type == ARMS) type = JSON::getValue("ClothesType_Arms");
    else if (this->type == LEGS)  type = JSON::getValue("ClothesType_Legs");
    else type = JSON::getValue("ClothesType_None");

    return type;
}

void Clothes::initClothes()
{
    Logger::out("Function starts", "Clothes::initClothes");
}
