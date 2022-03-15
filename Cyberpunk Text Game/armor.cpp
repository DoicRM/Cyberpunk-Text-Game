#include "Armor.h"

Armor::Armor() : Item()
{
	this->armorType = -1;
	this->defence = 0;
}

Armor::Armor(string name, string type, int armorType, string description, int defence, float price)
{
	this->armorType = armorType;
	this->defence = defence;
}

Armor::~Armor()
{
}