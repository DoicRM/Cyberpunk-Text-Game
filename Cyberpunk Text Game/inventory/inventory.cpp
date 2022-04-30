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
            Logger::out("<b>" + item->getName() + "</b> added to EQ", "Inventory::addItem");
    }

    updateInvFile();
}

void Inventory::addItems(Item* item, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        itemsList.push_back(item);
    }

    for (auto j : itemsList)
    {
        if (j == item)
            Logger::out("<b>" + item->getName() + "</b> added to EQ", "Inventory::addItems");
    }

    updateInvFile();
}

void Inventory::removeItem(Item* item)
{
    for (int i = 0; i < itemsList.size(); i++)
    {
        if (itemsList[i] == item)
            itemsList.erase(itemsList.begin() + i);
        break;
    }

    updateInvFile();
}

void Inventory::removeItems(Item* item, int amount)
{
    for (int i = 0; i < itemsList.size(); i++)
    {
        for (int j = 0; j < amount; j++)
        {
            if (itemsList[i] == item)
                itemsList.erase(itemsList.begin() + i);
        }

        break;
    }

    updateInvFile();
}

void Inventory::updateInvFile()
{
    std::ofstream eq;
    eq.open("eq.txt");

    if (eq.good())
    {
        Logger::out("Access to txt file", "Inventory::updateInvFile");

        if (itemsList.empty())
        {
            eq << "..." << std::endl;
        }
        else
        {
            for (auto i : itemsList)
            {
                eq << "Name: " << i->getName() << std::endl;
                eq << "Type: " << i->printType() << std::endl;
                eq << "Description: " << i->getDescription() << std::endl;
                eq << "Price: " << i->getPrice() << "$" << std::endl;
                eq << "..........................................................................." << std::endl;
            }
        }

        eq.close();
    }
    else Logger::error("No file access", "Inventory::updateInvFile");
}

void Inventory::showInv()
{
    if (itemsList.empty())
    {
        Display::write("\tYou do not have any items in your inventory.", 15);
    }
    else
    {
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

    updateInvFile();
}

bool Inventory::hasItem(Item* item)
{
    for (auto i : itemsList)
        if (i == item) return true;
    return false;
}