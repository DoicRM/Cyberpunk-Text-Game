#include "item.h"

Item::Item()
{
    this->name = "None";
    this->type = none;
    this->description = "None";
    this->price = 0.0;

    nextItem = 0;
}

Item::Item(string name, int type, string description, float price)
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

string Item::printType()
{
    string type;

    if (this->type == weapon)
    {
        type = "Weapons";
    }
    else if (this->type == armor)
    {
        type = "Armors";
    }
    else if (this->type == other)
    {
        type = "Others";
    }
    else if (this->type == quest)
    {
        type = "Quest";
    }
    else
    {
        type = "None";
    }

    return type;
}