#include "inventory.hpp"
#include "../utilities/logger/logger.hpp"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item* item)
{
    inventory.push_back(item);

    std::ofstream eq;
    eq.open("eq.txt", std::ios::app);

    if (eq.good())
    {
        Logger::out("Access to txt file", "Inventory::addItem");
        eq << "  Name: " << item->getName() << std::endl;
        eq << "  Type: " << item->printType() << std::endl;
        eq << "  Description: " << item->getDescription() << std::endl;
        eq << "  Price: " << item->getPrice() << "$" << std::endl;
        eq << "..........................................................................." << std::endl;
        eq.close();
    }
    else Logger::error("No file access", "Inventory::addItem");
}

void Inventory::removeItem(Item* item)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i] == item)
            inventory.erase(inventory.begin()+i);
    }
}

void Inventory::showInv()
{
    for (auto i : inventory)
    {
        std::cout << "  Name: " << i->getName() << std::endl;
        std::cout << "  Type: " << i->printType() << std::endl;
        std::cout << "  Description: " << i->getDescription() << std::endl;
        std::cout << "  Price: " << i->getPrice() << "$" << std::endl;
    }
}

void Inventory::clearInv()
{
    inventory.clear();  

    if (inventory.empty())
        Logger::out("Inventory is empty", "Inventory::clearInv");
}

bool Inventory::hasItem(Item* item)
{
    for (auto i : inventory)
    {
        if (i == item)
            return true;
    }

    return false;
}