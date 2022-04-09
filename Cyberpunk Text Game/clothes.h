#pragma once
#include "item.h"
#include "enums.h"

class Clothes : public Item
{
private:
	int clothesType;
	int defence;

public:
	Clothes();
	Clothes(std::string name, int type, int clothesType, std::string description, int defence, float price);
	virtual ~Clothes();

	std::string printClothesType();

	inline const int& getClothesType() const { return this->clothesType; }
	inline const int& getDefence() const { return this->defence; }

	static void initClothes_EN();
	static void initClothes_PL();
};