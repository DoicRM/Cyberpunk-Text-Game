#pragma once
#include "Item.h"
#include "enums.h"

using namespace std;

class Armor : public Item
{
private:
	int armorType;
	int defence;

public:
	Armor();
	Armor(string name, int type, int armorType, string description, int defence, float price);
	virtual ~Armor();

	string printArmorType();

	inline const int& getArmorType() const { return this->armorType; }
	inline const int& getDefence() const { return this->defence; }
};