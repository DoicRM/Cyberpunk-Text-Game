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

    if (this->type == HEAD) type = jWriter.at("ClothesTypes").value("Head", JSON_VALUE_ERROR);
    else if (this->type == CHEST) type = jWriter.at("ClothesTypes").value("Chest", JSON_VALUE_ERROR);
    else if (this->type == ARMS) type = jWriter.at("ClothesTypes").value("Arms", JSON_VALUE_ERROR);
    else if (this->type == LEGS)  type = jWriter.at("ClothesTypes").value("Legs", JSON_VALUE_ERROR);
    else type = jWriter.at("ClothesTypes").value("None", JSON_VALUE_ERROR);

    return type;
}

void Clothes::initClothes()
{
    Logger::startFuncLog(__FUNCTION__);
}
