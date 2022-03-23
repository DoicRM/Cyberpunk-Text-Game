#include "weapon.h"

Weapon::Weapon() : Item()
{
	this->damageMin = 0;
	this->damageMax = 0;
}

Weapon::Weapon(std::string name, int type, std::string description, int damageMin, int damageMax, float price) : Item(name, type, description, price)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{
}

void Weapon::initWeapons()
{
	Logger::out("Function start", "Weapon::initWeapons");

	Weapon Pistol("Pistol", WEAPON, "A simple weapon that shoots pure energy.", 10, 15, 250);
	Item::items["Pistol"] = Pistol;
}