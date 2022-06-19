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
    if (this->type == ClothesType::HEAD)
    {
        return jWriter["clothesType"]["head"];
    }
    else if (this->type == ClothesType::CHEST)
    {
        return jWriter["clothesType"]["chest"];
    }
    else if (this->type == ClothesType::ARMS)
    {
        return jWriter["clothesType"]["arms"];
    }
    else if (this->type == ClothesType::LEGS)
    {
        return jWriter["clothesType"]["legs"];
    }

    return jWriter["clothesType"]["none"];
}

void Clothes::initClothes()
{
    Logger::startFuncLog(__FUNCTION__);
}
