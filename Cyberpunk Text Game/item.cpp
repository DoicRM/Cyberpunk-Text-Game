#include "item.h"

Item::Item()
{
    this->name = "None";
    this->type = "None";
    this->description = "None";
    this->price = 0.0;

    nextItem = 0;
}

Item::Item(string name, string type, string description, float price)
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