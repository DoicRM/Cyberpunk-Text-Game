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
        {
            Logger::out("<b>" + item->getName() + "</b> added to EQ", __FUNCTION__);
        }
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
        {
            Logger::out("<b>" + item->getName() + "</b> added to EQ", __FUNCTION__);
        }
    }

    updateInvFile();
}

void Inventory::removeItem(Item* item)
{
    for (int i = 0; i < itemsList.size(); i++)
    {
        if (itemsList[i] == item)
        {
            itemsList.erase(itemsList.begin() + i);
        }

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
            {
                itemsList.erase(itemsList.begin() + i);
            }
        }

        break;
    }

    updateInvFile();
}

void Inventory::updateInvFile()
{
    std::ofstream eq;
    eq.open("eq.txt");

    if (!eq.good())
    {
        return Logger::error("No file access", __FUNCTION__);;
    }

    Logger::success("Access to txt file", __FUNCTION__);

    if (itemsList.empty())
    {
        eq << jWriter.at("InventoryInfos").value("NoItemsInInv", JSON_VALUE_ERROR) << std::endl;
        return;
    }

    for (auto i : itemsList)
    {
        eq << jWriter.at("ItemsInfos").value("Name", JSON_VALUE_ERROR) << i->getName() << std::endl;
        eq << jWriter.at("ItemsInfos").value("Type", JSON_VALUE_ERROR) << i->printType() << std::endl;
        eq << jWriter.at("ItemsInfos").value("Description", JSON_VALUE_ERROR) << i->getDescription() << std::endl;
        eq << jWriter.at("ItemsInfos").value("Price", JSON_VALUE_ERROR) << i->getPrice() << "$" << std::endl;
        eq << "..........................................................................." << std::endl;
    }

    eq.close();
}

void Inventory::showInv()
{
    if (itemsList.empty())
    {
        return Display::write("\t" + jWriter.at("InventoryInfos").value("NoItemsInInv", JSON_VALUE_ERROR), 15);
    }

    for (int i = 0; i < itemsList.size(); i++)
    {
        std::cout << "\t" << (i + 1) << ". " << itemsList[i]->getName() << std::endl;
    }

    Display::write(jWriter.at("InventoryInfos").value("SelectInvIndex", JSON_VALUE_ERROR), 15);
    int itemNr = Input::getChoice();
    showItemInfo(itemNr);
}

void Inventory::showItemInfo(int index)
{
    if (index <= 0 && index == (itemsList.size() + 1))
    {
        return Display::write("\t" + jWriter.at("InventoryInfos").value("SelectedIndexNotExists", JSON_VALUE_ERROR), 0);
    }

    std::cout << "\t" << jWriter.at("ItemsInfos").value("Name", JSON_VALUE_ERROR) << itemsList[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1]->getName() << std::endl;
    std::cout << "\t" << jWriter.at("ItemsInfos").value("Type", JSON_VALUE_ERROR) << itemsList[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1]->printType() << std::endl;
    std::cout << "\t" << jWriter.at("ItemsInfos").value("Description", JSON_VALUE_ERROR) << itemsList[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1]->getDescription() << std::endl;
    std::cout << "\t" << jWriter.at("ItemsInfos").value("Price", JSON_VALUE_ERROR) << itemsList[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1]->getPrice() << "$" << std::endl;
}

void Inventory::clearInv()
{
    if (itemsList.empty())
    {
        itemsList.clear();
        updateInvFile();
    }
       
    Logger::out("Inventory is empty", __FUNCTION__);
}

bool Inventory::hasItem(Item* item)
{
    for (auto i : itemsList)
    {
        if (i == item)
        {
            return true;
        }
    }

    return false;
}