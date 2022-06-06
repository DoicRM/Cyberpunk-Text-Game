#pragma once
#include "../events/events.hpp"
#include "../inventory/inventory.hpp"
#include "../journal/journal.hpp"

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
    Journal journal;

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
    void addItems(Item* item, int amount) { this->inventory.addItems(item, amount); }
    void removeItem(Item* item) { this->inventory.removeItem(item); }
    void removeItems(Item* item, int amount) { this->inventory.removeItems(item, amount); }
    void addQuest(Quest* quest) { this->journal.addQuest(quest); };
    void endQuest(Quest* quest) { this->journal.endQuest(quest); };
    void showInv() { this->inventory.showInv(); };
    void clearInv() { this->inventory.clearInv(); };
    bool hasItem(Item* item) { return this->inventory.hasItem(item); }

    inline const std::string& getName() const { return this->name; }
    inline const int& getHP() const { return this->hp; }
    inline const float& getMoney() const { return this->money; }

    static std::map <int, Hero> heroes;
    static void initHero();
};
