#include "weapon.h"

Weapon::Weapon() : Item()
{
	this->damageMax = 0;
	this->damageMin = 0;
}

Weapon::Weapon(string name, string type, string description, int damageMin, int damageMax, float price) : Item(name, type, description, price)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{

}