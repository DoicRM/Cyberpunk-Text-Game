#pragma once
#include <string>
#include "enums.h"

using namespace std;

class Item
{
public:
    string name;
    int type;
    string description;
    float price;
    Item* nextItem; // wskaŸnik na nastêpny element

    Item();
    Item(string name, int type, string description, float price);
    virtual ~Item();

    string printType();

    inline const string& getName() const { return this->name; };
    inline const int& getType() const { return this->type; };
    inline const string& getDescription() const { return this->description; };
    inline const float& getPrice() const { return this->price; };
};
