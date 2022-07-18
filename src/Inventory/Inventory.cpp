#include "Inventory.hpp"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item* itemPtr)
{
    itemsList.push_back(itemPtr);

    for (auto item : itemsList)
    {
        if (item == itemPtr)
        {
            Logger::out("<b>" + itemPtr->getName() + "</b> added to EQ", __FUNCTION__);
        }
    }

    updateInvFile();
}

void Inventory::addItems(Item* itemPtr, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        itemsList.push_back(itemPtr);
    }

    for (auto item : itemsList)
    {
        if (item == itemPtr)
        {
            Logger::out("<b>" + itemPtr->getName() + "</b> added to EQ", __FUNCTION__);
        }
    }

    updateInvFile();
}

void Inventory::removeItem(Item* itemPtr)
{
    if (!hasItem(itemPtr))
    {
        return;
    }

    for (int i = 0; i < itemsList.size(); i++)
    {
        if (itemsList[i] == itemPtr)
        {
            itemsList.erase(itemsList.begin() + i);
        }

        break;
    }

    updateInvFile();
}

void Inventory::removeItems(Item* itemPtr, int amount)
{
    if (!hasItems(itemPtr, amount))
    {
        return;
    }

    for (int i = 0; i < itemsList.size(); i++)
    {
        for (int j = 0; j < amount; j++)
        {
            if (itemsList[i] == itemPtr)
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
    eq.open("inventory.txt");

    if (!eq.is_open())
    {
        return Logger::error("Unable to open file", __FUNCTION__);
    }

    if (itemsList.empty())
    {
        eq << (std::string)json["inventory"]["noItems"] << std::endl;
        eq.close();
        return;
    }

    for (auto item : itemsList)
    {
        eq << (std::string)json["item"]["name"] << item->getName() << std::endl;
        eq << (std::string)json["item"]["type"] << item->printType() << std::endl;
        eq << (std::string)json["item"]["description"] << item->getDescription() << std::endl;
        eq << (std::string)json["item"]["price"] << item->getPrice() << "$" << std::endl;
        eq << "..........................................................................." << std::endl;
    }

    eq.close();
}

void Inventory::showInv()
{
    if (itemsList.empty())
    {
        return Display::write("\t" + json["inventory"]["noItems"], 15);
    }

    for (int i = 0; i < itemsList.size(); i++)
    {
        std::cout << "\t" << (i + 1) << ". " << itemsList[i]->getName() << std::endl;
    }

    Display::write(json["inventory"]["selectIndex"], 15);
    int itemNr = Input::getChoice();
    showItemInfo(itemNr);
}

void Inventory::showItemInfo(int index)
{
    Item* indexNr = itemsList[index - 1];

    if (index <= 0 && index == (itemsList.size() + 1))
    {
        return Display::write("\t" + json["inventory"]["selectedIndexNotExists"], 0);
    }

    std::cout << "\t" << (std::string)json["item"]["name"] << indexNr->getName() << std::endl;
    std::cout << "\t" << (std::string)json["item"]["type"] << indexNr->printType() << std::endl;
    std::cout << "\t" << (std::string)json["item"]["description"] << indexNr->getDescription() << std::endl;
    std::cout << "\t" << (std::string)json["item"]["price"] << indexNr->getPrice() << "$" << std::endl;
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

bool Inventory::hasItem(Item* itemPtr)
{
    for (auto item : itemsList)
    {
        if (item == itemPtr)
        {
            return true;
        }
    }

    return false;
}

bool Inventory::hasItems(Item* itemPtr, int amount)
{
    int ownedItems = 0;

    for (auto item : itemsList)
    {
        if (item == itemPtr)
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
