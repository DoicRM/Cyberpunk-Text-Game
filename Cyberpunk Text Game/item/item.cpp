#include "item.hpp"

std::map <std::string, Item> Item::items;

Item::Item()
{
    this->name = "None";
    this->type = NONE;
    this->description = "None";
    this->price = 0.0;
    this->nextItem = 0;
}

Item::Item(std::string name, int type, std::string description, float price)
{
    this->name = name;
    this->type = type;
    this->description = description;
    this->price = price;
    this->nextItem = 0;
}

Item::~Item()
{
}

std::string Item::printType()
{
    std::string type;

    if (this->type == WEAPON) type = j["ItemsTypes"]["Weapon"];
    else if (this->type == CLOTHES) type = j["ItemsTypes"]["Clothes"];
    else if (this->type == OTHER) type = j["ItemsTypes"]["Other"];
    else if (this->type == FOOD) type = j["ItemsTypes"]["Food"];
    else if (this->type == QUEST) type = j["ItemsTypes"]["Quest"];
    else type = j["ItemsTypes"]["None"];

    return type;
}

void Item::initItems()
{
    Logger::out("Function starts", "Item::initItems");

    Item AD13(j["Items"]["AD13"]["Name"], OTHER, j["Items"]["AD13"]["Description"], 50);
    Item AccessCard(j["Items"]["AccessCard"]["Name"], OTHER, j["Items"]["AccessCard"]["Description"], 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
}