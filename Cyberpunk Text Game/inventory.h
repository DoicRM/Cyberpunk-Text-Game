#pragma once
#include <fstream>
#include <iostream>
#include "item.h"
#include "logger.h"

class Inventory
{
public:
    Item* firstItem; // wska�nik na pocz�tek listy

    Inventory();
    virtual ~Inventory();

    void addItem(Item* item);
    void removeItem(int index);
    void showInv();
    bool hasItem(Item* item);
};