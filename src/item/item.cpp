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
    if (this->type == WEAPON)
    {
        return jWriter["ItemsTypes"]["Weapon"];
    }
    else if (this->type == CLOTHES)
    {
        return jWriter["ItemsTypes"]["Clothes"];
    } 
    else if (this->type == OTHER)
    {
        return jWriter["ItemsTypes"]["Other"];
    }
    else if (this->type == FOOD)
    {
        return jWriter["ItemsTypes"]["Food"];
    }
    else if (this->type == QUEST)
    {
        return jWriter["ItemsTypes"]["Quest"];
    }

    return jWriter["ItemsTypes"]["None"];
}

void Item::initItems()
{
    Logger::startFuncLog(__FUNCTION__);

    Item AD13(jWriter["Items"]["AD13"]["Name"], OTHER, jWriter["Items"]["AD13"]["Description"], 50);
    Item AccessCard(jWriter["Items"]["AccessCard"]["Name"], OTHER, jWriter["Items"]["AccessCard"]["Description"], 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
}