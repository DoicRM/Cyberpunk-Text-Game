#pragma once
#include <string>

using namespace std;

enum itemType
{
    none = 0,
    weapon,
    armor,
    other,
    quest
};

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
