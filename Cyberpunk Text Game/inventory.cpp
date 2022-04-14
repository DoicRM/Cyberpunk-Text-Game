#include "inventory.hpp"
#include "logger.hpp"

Inventory::Inventory()
{
    this->firstItem = 0;
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item* item)
{
    Item* newItem = new Item;
    newItem = item;

    if (firstItem == 0) // sprawdzenie czy to pierwszy element listy
    {
        firstItem = newItem; // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
    }
    else
    {
        Item* temp = firstItem; // w przeciwnym wypadku trafia na koniec listy

        while (temp->nextItem) temp = temp->nextItem; // znajdowanie wskaŸnika na ostatni element

        temp->nextItem = newItem;  // ostatni element wskazuje na nowy item
        newItem->nextItem = 0;     // ostatni nie wskazuje na nic
    }

    std::fstream eq;
    eq.open("eq.txt", std::ios::out | std::ios::app);

    if (eq.good())
    {
        Logger::out("Access to txt file", "Inventory::addItem");
        eq << "  Name: " << newItem->getName() << std::endl;
        eq << "  Type: " << newItem->printType() << std::endl;
        eq << "  Description: " << newItem->getDescription() << std::endl;
        eq << "  Price: " << newItem->getPrice() << "$" << std::endl;
        eq << "..........................................................................." << std::endl;
        eq.close();
    }
    else Logger::error("No file access", "Inventory::addItem");
}

void Inventory::removeItem(int index)
{
    if (index == 1) // jezeli to pierwszy element listy
    {
        Item* temp = firstItem;
        firstItem = temp->nextItem; //ustawienie pocz¹tku na drugi element
        delete temp; // usuwanie starego pierwszego elementu z pamiêci
    }
    else if (index >= 2) // je¿eli nie jest to pierwszy element
    {
        int j = 1;
        // do usuniecia srodkowego elemetnu potrzeba wskaznika na item n-1
        // wskaznik *temp bedzie wskaznikiem na item poprzedzaj¹cy item usuwany
        Item* temp = firstItem;

        while (temp)
        {
            // sprawdzenie czy wskaznik jest na item n-1 niz usuwany
            if ((j + 1) == index) break;

            // jezeli nie to przewijanie pêtli do przodu
            temp = temp->nextItem;
            j++;
        }

        // wskaznik *temp wskazuje na item n-1
        // nadpisywanie wkaznik n-1 z item n na item n+1
        // bezpowrotnie utrata item n-tego

        if (temp->nextItem->nextItem == 0) // jezeli jest usuwany ostatni element listy
        {
            delete temp->nextItem;
            temp->nextItem = 0;
        }
        else // jezeli jest usuwany srodkowy element
        {
            Item* delItem = temp->nextItem;
            temp->nextItem = temp->nextItem->nextItem;
            delete delItem;
        }
    }
}

void Inventory::showInv()
{
    Item* temp = firstItem; // wskaŸnik na pierwszy element listy

    while (temp) // przewijanie wskaŸników na nastêpne elementy
    {
        std::cout << "  Name: " << temp->getName() << std::endl;
        std::cout << "  Type: " << temp->printType() << std::endl;
        std::cout << "  Description: " << temp->getDescription() << std::endl;
        std::cout << "  Price: " << temp->getPrice() << "$" << std::endl;
        temp = temp->nextItem;
    }
}

bool Inventory::hasItem(Item* item)
{
    Item* temp = firstItem; // wskaŸnik na pierwszy element listy

    while (temp)
    {
        if (temp == item) return true;
        else temp = temp->nextItem;
    }

    return false;
}