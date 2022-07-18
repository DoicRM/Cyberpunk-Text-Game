#include "Item.hpp"

std::map <std::string, Item> Item::items;

Item::Item()
{
    this->name = "None";
    this->type = ItemType::NONE;
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
    if (this->type == ItemType::WEAPON)
    {
        return json["itemType"]["weapon"];
    }
    else if (this->type == ItemType::CLOTHES)
    {
        return json["itemType"]["clothes"];
    }
    else if (this->type == ItemType::OTHER)
    {
        return json["itemType"]["other"];
    }
    else if (this->type == ItemType::FOOD)
    {
        return json["itemType"]["food"];
    }
    else if (this->type == ItemType::QUEST)
    {
        return json["itemType"]["quest"];
    }

    return json["itemType"]["none"];
}

void Item::initItems()
{
    Logger::startFuncLog(__FUNCTION__);

    Item AD13(json["items"]["ad13"]["name"], ItemType::OTHER, json["items"]["ad13"]["description"], 50);
    Item AccessCard(json["items"]["accessCard"]["name"], ItemType::OTHER, json["items"]["accessCard"]["description"], 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
}