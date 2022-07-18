#pragma once
#include "../Item.hpp"

class Weapon : public Item
{
private:
	int damageMin;
	int damageMax;

public:
	Weapon();
	Weapon(std::string name, int type, std::string description, int damageMin, int damageMax, float price);
	virtual ~Weapon();

	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }

	static void initWeapons();
};