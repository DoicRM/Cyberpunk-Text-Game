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

    if (this->type == WEAPON)
    {
        return type = jWriter.at("ItemsTypes").value("Weapon", JSON_VALUE_ERROR);
    }
    else if (this->type == CLOTHES)
    {
        return type = jWriter.at("ItemsTypes").value("Clothes", JSON_VALUE_ERROR);
    } 
    else if (this->type == OTHER)
    {
        return type = jWriter.at("ItemsTypes").value("Other", JSON_VALUE_ERROR);
    }
    else if (this->type == FOOD)
    {
        return type = jWriter.at("ItemsTypes").value("Food", JSON_VALUE_ERROR);
    }
    else if (this->type == QUEST)
    {
        return type = jWriter.at("ItemsTypes").value("Quest", JSON_VALUE_ERROR);
    }

    return type = jWriter.at("ItemsTypes").value("None", JSON_VALUE_ERROR);
}

void Item::initItems()
{
    Logger::startFuncLog(__FUNCTION__);

    Item AD13(jWriter.at("Items").at("AD13").value("Name", JSON_VALUE_ERROR), OTHER, jWriter.at("Items").at("AD13").value("Description", JSON_VALUE_ERROR), 50);
    Item AccessCard(jWriter.at("Items").at("AccessCard").value("Name", JSON_VALUE_ERROR), OTHER, jWriter.at("Items").at("AccessCard").value("Description", JSON_VALUE_ERROR), 0);

    items["AD13"] = AD13;
    items["AccessCard"] = AccessCard;
}