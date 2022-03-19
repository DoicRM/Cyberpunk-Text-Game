#include "inventory.h"

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
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        firstItem = newItem;
    }
    else
    {
        // w przeciwnym wypadku trafia na koniec listy
        Item* temp = firstItem;

        while (temp->nextItem)
        {
            // znajdowania wskaŸnika na ostatni element
            temp = temp->nextItem;
        }

        temp->nextItem = newItem;  // ostatni element wskazuje na nowy item
        newItem->nextItem = 0;     // ostatni nie wskazuje na nic
    }

    std::fstream eq;
    eq.open("eq.txt", std::ios::out | std::ios::app);
    eq << "  Name: " << newItem->name << std::endl;
    eq << "  Type: " << item->printType() << std::endl;
    eq << "  Description: " << newItem->description << std::endl;
    eq << "  Price: " << newItem->price << std::endl;
    eq << "..........................................................................." << std::endl;
    eq.close();
}

void Inventory::removeItem(int index)
{
    // jezeli to pierwszy element listy
    if (index == 1)
    {
        Item* temp = firstItem;
        firstItem = temp->nextItem; //ustawienie pocz¹tku na drugi element
        delete temp; // usuwanie starego pierwszego elementu z pamiêci
    }
    // je¿eli nie jest to pierwszy element
    else if (index >= 2)
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

        // jezeli jest usuwany ostatni element listy
        if (temp->nextItem->nextItem == 0) {
            delete temp->nextItem;
            temp->nextItem = 0;
        }
        // jezeli jest usuwany srodkowy element
        else {
            Item* delItem = temp->nextItem;
            temp->nextItem = temp->nextItem->nextItem;
            delete delItem;
        }
    }
}

void Inventory::showInv()
{
    Item* temp = firstItem; // wskaŸnik na pierwszy element listy

    // przewijanie wskaŸników na nastêpne elementy
    while (temp)
    {
        std::cout << "  Name: " << temp->name << std::endl;
        std::cout << "  Type: " << temp->printType() << std::endl;
        std::cout << "  Description: " << temp->description << std::endl;
        std::cout << "  Price: " << temp->price << std::endl;
        temp = temp->nextItem;
    }
}

bool Inventory::hasItem(Item* item)
{
    Item* temp = firstItem; // wskaŸnik na pierwszy element listy

    while (temp)
    {
        if (temp == item)
        {
            return true;
        }
        else
        {
            temp = temp->nextItem;
        }
    }

    return false;
}