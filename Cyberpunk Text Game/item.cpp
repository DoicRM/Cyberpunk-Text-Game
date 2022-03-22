#include "item.h"

Item::Item()
{
    this->name = "None";
    this->type = NONE;
    this->description = "None";
    this->price = 0.0;

    nextItem = 0;
}

Item::Item(std::string name, int type, std::string description, float price)
{
    this->name = name;
    this->type = type;
    this->description = description;
    this->price = price;

    nextItem = 0;
}

Item::~Item()
{
}

std::string Item::printType()
{
    std::string type;

    if (this->type == WEAPON) type = "Weapons";
    else if (this->type == ARMOR) type = "Armors";
    else if (this->type == OTHER) type = "Others";
    else if (this->type == FOOD) type = "Food";
    else if (this->type == QUEST) type = "Quest";
    else type = "None";

    return type;
}