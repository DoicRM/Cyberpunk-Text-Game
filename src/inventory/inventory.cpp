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
    if (!hasItem(item))
    {
        return;
    }
       
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
    if (!hasItems(item, amount))
    {
        return;
    }

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

    if (!eq.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }

    if (itemsList.empty())
    {
        eq << (std::string)jWriter["InventoryInfos"]["NoItemsInInv"] << std::endl;
        eq.close();
        return;
    }

    for (auto i : itemsList)
    {
        eq << (std::string)jWriter["ItemsInfos"]["Name"] << i->getName() << std::endl;
        eq << (std::string)jWriter["ItemsInfos"]["Type"] << i->printType() << std::endl;
        eq << (std::string)jWriter["ItemsInfos"]["Description"] << i->getDescription() << std::endl;
        eq << (std::string)jWriter["ItemsInfos"]["Price"] << i->getPrice() << "$" << std::endl;
        eq << "..........................................................................." << std::endl;
    }

    eq.close();
}

void Inventory::showInv()
{
    if (itemsList.empty())
    {
        return Display::write("\t" + jWriter["InventoryInfos"]["NoItemsInInv"], 15);
    }

    for (int i = 0; i < itemsList.size(); i++)
    {
        std::cout << "\t" << (i + 1) << ". " << itemsList[i]->getName() << std::endl;
    }

    Display::write(jWriter["InventoryInfos"]["SelectInvIndex"], 15);
    int itemNr = Input::getChoice();
    showItemInfo(itemNr);
}

void Inventory::showItemInfo(int index)
{
    Item* indexNr = itemsList[static_cast<std::vector<Item*, std::allocator<Item*>>::size_type>(index) - 1];

    if (index <= 0 && index == (itemsList.size() + 1))
    {
        return Display::write("\t" + jWriter["InventoryInfos"]["SelectedIndexNotExists"], 0);
    }

    std::cout << "\t" << (std::string)jWriter["ItemsInfos"]["Name"] << indexNr->getName() << std::endl;
    std::cout << "\t" << (std::string)jWriter["ItemsInfos"]["Type"] << indexNr->printType() << std::endl;
    std::cout << "\t" << (std::string)jWriter["ItemsInfos"]["Description"] << indexNr->getDescription() << std::endl;
    std::cout << "\t" << (std::string)jWriter["ItemsInfos"]["Price"] << indexNr->getPrice() << "$" << std::endl;
}

void Inventory::clearInv()
{
    if (!itemsList.empty())
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

bool Inventory::hasItems(Item* item, int amount)
{
    int ownedItems = 0;

    for (auto i : itemsList)
    {
        if (i == item)
        {
            ownedItems += 1;
        }
    }

    if (ownedItems >= amount)
    {
        return true;
    }

    return false;
}