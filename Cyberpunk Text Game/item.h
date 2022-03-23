#pragma once
#include <string>
#include <map>
#include "enums.h"
#include "logger.h"

class Item
{
public:
    std::string name;
    int type;
    std::string description;
    float price;
    Item* nextItem; // wskaŸnik na nastêpny element

    Item();
    Item(std::string name, int type, std::string description, float price);
    virtual ~Item();

    std::string printType();

    inline const std::string& getName() const { return this->name; };
    inline const int& getType() const { return this->type; };
    inline const std::string& getDescription() const { return this->description; };
    inline const float& getPrice() const { return this->price; };

    static std::map <std::string, Item> items;
    static void initItems();
};
