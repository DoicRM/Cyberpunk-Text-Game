#pragma once
#include "../item/item.hpp"
#include "../utilities/logger/logger.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();

    void addItem(Item* item);
    void removeItem(Item* item);
    void showInv();
    void clearInv();
    bool hasItem(Item* item);

private:
    std::vector<Item*>inventory;
};