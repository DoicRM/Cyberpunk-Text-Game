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

    if (firstItem == 0) // sprawdzamy czy to pierwszy element listy
    {
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        firstItem = newItem;
    }
    else
    {
        // w przeciwnym wypadku wêdrujemy na koniec listy
        Item* temp = firstItem;

        while (temp->nextItem)
        {
            // znajdujemy wskaŸnik na ostatni element
            temp = temp->nextItem;
        }

        temp->nextItem = newItem;  // ostatni element wskazuje na nasz nowy
        newItem->nextItem = 0;     // ostatni nie wskazuje na nic
    }

    fstream eq;
    eq.open("eq.txt", ios::out | ios::app);
    eq << "  Name: " << newItem->name << endl;
    eq << "  Type: " << newItem->type << endl;
    eq << "  Description: " << newItem->description << endl;
    eq << "  Price: " << newItem->price << endl;
    eq << "..........................................................................." << endl;
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
    Item* temp = firstItem; // wskaŸnik na pierszy element listy

    // przewijanie wskaŸników na nastêpne elementy
    while (temp)
    {
        cout << "  Name: " << temp->name << endl;
        cout << "  Type: " << temp->type << endl;
        cout << "  Description: " << temp->description << endl;
        cout << "  Price: " << temp->price << endl;
        temp = temp->nextItem;
    }
}

bool Inventory::isHeroHaveItem(Item* item)
{
    Item* temp = firstItem; // wskaŸnik na pierszy element listy

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