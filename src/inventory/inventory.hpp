#pragma once
#include "../item/item.hpp"
#include "../utilities/logger/logger.hpp"
#include "../utilities/languageHandler/languageHandler.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();

    void addItem(Item* item);
    void addItems(Item* item, int amount);
    void removeItem(Item* item);
    void removeItems(Item* item, int amount);
    void updateInvFile();
    void showInv();
    void showItemInfo(int index);
    void clearInv();
    bool hasItem(Item* item);
    bool hasItems(Item* item, int amount);

private:
    std::vector<Item*>itemsList;
};