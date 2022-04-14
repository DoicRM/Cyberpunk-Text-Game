#pragma once
#include "item.hpp"
#include "logger.hpp"
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
    bool hasItem(Item* item);
};