#pragma once
#include "events.hpp"
#include "inventory.hpp"

class Hero
{
private:
    std::string name;
    int sex;
    int hp;
    float money;
    Inventory inventory;
    Weapon weapon;
    Clothes clothes;

public:
    Hero();
    virtual ~Hero();

    void setName(std::string name) { this->name = name; }
    void setSex(int sex) { this->sex = sex; }
    void addHP(int hp) { this->hp += hp; }
    void removeHP(int hp);
    void kill();
    void addMoney(float money) { this->money += money; }
    void removeMoney(float money) { if (this->money > 0) this->money -= money; }
    bool isDead() { return this->hp < 0; }
    void addItem(Item* item) { this->inventory.addItem(item); }
    void removeItem(int index) { this->inventory.removeItem(index); }
    void showInv() { this->inventory.showInv(); };
    bool hasItem(Item* item) { return this->inventory.hasItem(item); }

    inline const std::string& getName() const { return this->name; }
    inline const int& getHP() const { return this->hp; }
    inline const float& getMoney() const { return this->money; }

    static std::map <int, Hero> heroes;
    static void initHero();
};
