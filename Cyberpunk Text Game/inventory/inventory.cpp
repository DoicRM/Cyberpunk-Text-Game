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
    itemsList.push_back(item);

    for (auto i : itemsList)
    {
        if (i == item)
            Logger::out(item->getName() + "added to EQ", "Inventory::addItem");
    }

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
    for (int i = 0; i < itemsList.size(); i++)
    {
        if (itemsList[i] == item)
            itemsList.erase(itemsList.begin()+i);
        break;
    }
}

void Inventory::showInv()
{
    if (itemsList.empty())
    {
        Display::write("\tYou do not have any items in your inventory.", 15);
    }
    else {
        for (int i = 0; i < itemsList.size(); i++)
        {
            std::cout << "\t" << (i + 1) << ". " << itemsList[i]->getName() << std::endl;
        }

        Display::write("\tSelect the index of the item you want to view.\n", 15);
        int itemNr = Input::getChoice();
        itemNr = itemNr - 1;
        showItemInfo(itemNr);
    }
}

void Inventory::showItemInfo(int index)
{
    std::cout << "\tName: " << itemsList[index]->getName() << std::endl;
    std::cout << "\tType: " << itemsList[index]->printType() << std::endl;
    std::cout << "\tDescription: " << itemsList[index]->getDescription() << std::endl;
    std::cout << "\tPrice: " << itemsList[index]->getPrice() << "$" << std::endl;
}

void Inventory::clearInv()
{
    itemsList.clear();

    if (itemsList.empty())
        Logger::out("Inventory is empty", "Inventory::clearInv");
}

bool Inventory::hasItem(Item* item)
{
    for (auto i : itemsList)
        if (i == item) return true;

    return false;
}