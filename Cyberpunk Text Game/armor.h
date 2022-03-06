#pragma once
#include "Item.h"

using namespace std;

enum armorType { HEAD = 0, CHEST, ARMS, LEGS };

class Armor : public Item
{
private:
	int armorType;
	int defence;

public:
	Armor();
	Armor(string name, string type, int armorType, string description, int defence, float price);
	virtual ~Armor();

	inline const int& getArmorType() const { return this->armorType; }
	inline const int& getDefence() const { return this->defence; }
};