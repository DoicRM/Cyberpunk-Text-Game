#pragma once
#include "../utilities/utilities.hpp"
#include "../utilities/logger/logger.hpp"
#include "../utilities/languageHandler/languageHandler.hpp"
#include <string>
#include <map>

class Item
{
public:
    std::string name;
    int type;
    std::string description;
    float price;
    Item* nextItem; // wska�nik na nast�pny element

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
