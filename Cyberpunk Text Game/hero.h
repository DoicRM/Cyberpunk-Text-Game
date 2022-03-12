#pragma once
#include "events.h"
#include "inventory.h"

using namespace std;

class Hero
{
private:
    string name;
    int hp;
    //int exp;
    //int level;
    float money;
    Inventory inventory;
    Weapon weapon;
    Armor armor;

public:
    Hero();
    virtual ~Hero();

    void setName(string name);
    void addHP(int hp);
    void removeHP(int hp);
    void kill();
    void addMoney(float money);
    void removeMoney(float money);
    bool isDead() { return this->hp < 0; };
    void addItem(Item* item) { this->inventory.addItem(item); };
    void removeItem(int index) { this->inventory.removeItem(index); };
    void showInv() { this->inventory.showInv(); };
    bool hasItem(Item* item) { return this->inventory.hasItem(item); };

    inline const string& getName() const { return this->name; };
    inline const int& getHP() const { return this->hp; };
    inline const float& getMoney() const { return this->money; };
};
