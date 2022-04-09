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

void Weapon::initWeapons_EN()
{
	Logger::out("Function start", "Weapon::initWeapons_EN");

	Weapon Pistol("Pistol", WEAPON, "A simple weapon that shoots pure energy.", 10, 15, 250);
	Item::items["Pistol"] = Pistol;
}

void Weapon::initWeapons_PL()
{
	Logger::out("Function start", "Weapon::initWeapons_PL");

	Weapon Pistol("Pistolet", WEAPON, "Prosta broñ strzelaj¹ca czyst¹ energi¹.", 10, 15, 250);
	Item::items["Pistol"] = Pistol;
}