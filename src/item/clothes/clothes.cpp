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
    if (this->type == HEAD)
    {
        return jWriter["ClothesTypes"]["Head"];
    }
    else if (this->type == CHEST)
    {
        return jWriter["ClothesTypes"]["Chest"];
    }
    else if (this->type == ARMS)
    {
        return jWriter["ClothesTypes"]["Arms"];
    }
    else if (this->type == LEGS)
    {
        return jWriter["ClothesTypes"]["Legs"];
    }

    return jWriter["ClothesTypes"]["None"];
}

void Clothes::initClothes()
{
    Logger::startFuncLog(__FUNCTION__);
}
