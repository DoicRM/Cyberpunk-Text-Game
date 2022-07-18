#include "Clothes.hpp"

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
        return json["clothesType"]["head"];
    }
    else if (this->type == ClothesType::CHEST)
    {
        return json["clothesType"]["chest"];
    }
    else if (this->type == ClothesType::ARMS)
    {
        return json["clothesType"]["arms"];
    }
    else if (this->type == ClothesType::LEGS)
    {
        return json["clothesType"]["legs"];
    }

    return json["clothesType"]["none"];
}

void Clothes::initClothes()
{
    Logger::startFuncLog(__FUNCTION__);
}
