#pragma once
#include "../item/item.hpp"
#include "../logger/logger.hpp"
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
    bool hasItem(Item* item);
};