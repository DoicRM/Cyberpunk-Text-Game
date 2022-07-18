#pragma once
#include "../Utilities/Utilities.hpp"
#include "../Utilities/Logger/Logger.hpp"
#include "../Utilities/JsonHandler/JsonHandler.hpp"
#include <string>
#include <map>

enum ItemType
{
    NONE, WEAPON, CLOTHES, FOOD, OTHER, QUEST
};

class Item
{
public:
    std::string name;
    int type;
    std::string description;
    float price;
    Item* nextItem;

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
