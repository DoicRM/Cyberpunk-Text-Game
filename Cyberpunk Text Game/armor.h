#pragma once
#include "Item.h"

using namespace std;

enum armorType
{
	head = 0,
	chest,
	arms,
	legs
};

class Armor : public Item
{
private:
	int armorType;
	int defence;

public:
	Armor();
	Armor(string name, int type, int armorType, string description, int defence, float price);
	virtual ~Armor();

	inline const int& getArmorType() const { return this->armorType; }
	inline const int& getDefence() const { return this->defence; }
};