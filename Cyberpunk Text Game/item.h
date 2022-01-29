#pragma once
#include <string>

using namespace std;

class Item
{
public:
    string name;
    string type;
    string description;
    float price;
    Item* nextItem; // wskaŸnik na nastêpny element

    Item(string = "none", string = "none", string = "none", float = 0.0);
    virtual ~Item();

    inline const string& getName() const { return this->name; };
    inline const string& getType() const { return this->type; };
    inline const string& getDescription() const { return this->description; };
    inline const float& getPrice() const { return this->price; };
};
