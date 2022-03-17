#include "weapon.h"

Weapon::Weapon() : Item()
{
	this->damageMin = 0;
	this->damageMax = 0;
}

Weapon::Weapon(string name, int type, string description, int damageMin, int damageMax, float price) : Item(name, type, description, price)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{
}