#pragma once
#include "item.h"
#include <fstream>
#include <iostream>

class Inventory
{
public:
    Item* firstItem; // wska�nik na pocz�tek listy

    Inventory();
    virtual ~Inventory();

    void addItem(Item* item);
    void removeItem(int index);
    void showInv();
    bool isHeroHaveItem(Item* item);
};