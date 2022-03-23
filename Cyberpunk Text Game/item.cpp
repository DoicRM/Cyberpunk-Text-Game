#include "item.h"

std::map <std::string, Item> Item::items;

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

void Item::initItems()
{
    Logger::out("Function start", "Item::initItems");

    Item AD13("Accelerator D-13", OTHER, "A long gone accelerator model, though still quite precious.", 50);
    Item AccessCard("Access card", OTHER, "It definitely matches the door leading to the locked room in Ramsey's office.", 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
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