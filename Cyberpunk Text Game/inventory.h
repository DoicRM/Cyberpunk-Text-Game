#pragma once
#include "item.h"
#include <fstream>
#include <iostream>

class Inventory
{
public:
    Item* firstItem; // wskaünik na poczπtek listy

    Inventory();
    virtual ~Inventory();

    void addItem(Item* item);
    void removeItem(int index);
    void showInv();
    bool isHeroHaveItem(Item* item);
};