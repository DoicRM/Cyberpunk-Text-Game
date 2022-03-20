#include "armor.h"

Armor::Armor() : Item()
{
	this->armorType = -1;
	this->defence = 0;
}

Armor::Armor(std::string name, int type, int armorType, std::string description, int defence, float price)
{
	this->armorType = armorType;
	this->defence = defence;
}

Armor::~Armor()
{
}

std::string Armor::printArmorType()
{
    std::string type;

    if (this->type == HEAD)
    {
        type = "Head";
    }
    else if (this->type == CHEST)
    {
        type = "Chest";
    }
    else if (this->type == ARMS)
    {
        type = "Arms";
    }
    else if (this->type == LEGS)
    {
        type = "Legs";
    }
    else
    {
        type = "None";
    }

    return type;
}