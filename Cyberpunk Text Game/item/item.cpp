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

    if (this->type == WEAPON) type = JSON::getValue("ItemType_Weapon");
    else if (this->type == CLOTHES) type = JSON::getValue("ItemType_Clothes");
    else if (this->type == OTHER) type = JSON::getValue("ItemType_Other");
    else if (this->type == FOOD) type = JSON::getValue("ItemType_Food");
    else if (this->type == QUEST) type = JSON::getValue("ItemType_Quest");
    else type = JSON::getValue("ItemType_None");;

    return type;
}

void Item::initItems()
{
    Logger::out("Function starts", "Item::initItems");

    Item AD13(JSON::getValue("Item_AD13_Name"), OTHER, JSON::getValue("Item_AD13_Desc"), 50);
    Item AccessCard(JSON::getValue("Item_AccessCard_Name"), OTHER, JSON::getValue("Item_AccessCard_Desc"), 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
}