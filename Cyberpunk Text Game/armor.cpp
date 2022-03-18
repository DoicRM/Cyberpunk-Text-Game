#include "Armor.h"

Armor::Armor() : Item()
{
	this->armorType = -1;
	this->defence = 0;
}

Armor::Armor(string name, int type, int armorType, string description, int defence, float price)
{
	this->armorType = armorType;
	this->defence = defence;
}

Armor::~Armor()
{
}

string Armor::printArmorType()
{
    string type;

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