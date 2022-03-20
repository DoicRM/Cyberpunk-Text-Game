#pragma once
#include "item.h"
#include "enums.h"

class Armor : public Item
{
private:
	int armorType;
	int defence;

public:
	Armor();
	Armor(std::string name, int type, int armorType, std::string description, int defence, float price);
	virtual ~Armor();

	std::string printArmorType();

	inline const int& getArmorType() const { return this->armorType; }
	inline const int& getDefence() const { return this->defence; }
};