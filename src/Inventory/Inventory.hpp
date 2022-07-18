#pragma once
#include "../Item/Item.hpp"
#include "../Utilities/Logger/Logger.hpp"
#include "../Utilities/JsonHandler/JsonHandler.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class Inventory
{
public:
    Inventory();
    virtual ~Inventory();

    void addItem(Item* itemPtr);
    void addItems(Item* itemPtr, int amount);
    void removeItem(Item* itemPtr);
    void removeItems(Item* itemPtr, int amount);
    void updateInvFile();
    void showInv();
    void showItemInfo(int index);
    void clearInv();
    bool hasItem(Item* itemPtr);
    bool hasItems(Item* itemPtr, int amount);

private:
    std::vector<Item*>itemsList;
};