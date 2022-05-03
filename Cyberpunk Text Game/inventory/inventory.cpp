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
            eq << j["Infos"].value("NoItemsInInv", "") << std::endl;
        }
        else
        {
            for (auto i : itemsList)
            {
                eq << j["ItemsInfos"].value("Name","") << i->getName() << std::endl;
                eq << j["ItemsInfos"].value("Type", "") << i->printType() << std::endl;
                eq << j["ItemsInfos"].value("Description", "") << i->getDescription() << std::endl;
                eq << j["ItemsInfos"].value("Price", "") << i->getPrice() << "$" << std::endl;
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
        Display::write("\t" + j["InventoryInfos"].value("NoItemsInInv", ""), 15);
    }
    else
    {
        for (int i = 0; i < itemsList.size(); i++)
        {
            std::cout << "\t" << (i + 1) << ". " << itemsList[i]->getName() << std::endl;
        }

        Display::write(j["InventoryInfos"].value("SelectInvIndex", ""), 15);
        int itemNr = Input::getChoice();
        showItemInfo(itemNr);
    }
}

void Inventory::showItemInfo(int index)
{
    if (index <= 0 && index == (itemsList.size() + 1))
    {
        std::cout << "\t" + j["InventoryInfos"].value("SelectedIndexNotExists", "") << std::endl;
    }
    else
    {
        std::cout << "\t" << j["ItemsInfos"].value("Name", "") << itemsList[index - 1]->getName() << std::endl;
        std::cout << "\t" << j["ItemsInfos"].value("Type", "") << itemsList[index - 1]->printType() << std::endl;
        std::cout << "\t" << j["ItemsInfos"].value("Description", "") << itemsList[index - 1]->getDescription() << std::endl;
        std::cout << "\t" << j["ItemsInfos"].value("Price", "") << itemsList[index - 1]->getPrice() << "$" << std::endl;
    }
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
    {
        if (i == item) return true;
    }

    return false;
}