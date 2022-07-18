#pragma once
#include "../Npc.hpp"
#include "../../Event/Event.hpp"
#include "../../Inventory/Inventory.hpp"
#include "../../Journal/Journal.hpp"

class Hero : public Npc
{
private:
    int hp;
    float money;
    Weapon weapon;
    Clothes clothes;
    Inventory inventory;
    Journal journal;

public:
    Hero();
    virtual ~Hero();

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
    void addQuest(Quest* quest) { this->journal.addQuest(quest); }
    void endQuest(Quest* quest, int status) { this->journal.endQuest(quest, status); }
    void showInv() { this->inventory.showInv(); }
    void clearInv() { this->inventory.clearInv(); }
    bool hasItem(Item* item) { return this->inventory.hasItem(item); }

    inline const int& getHP() const { return this->hp; }
    inline const float& getMoney() const { return this->money; }

    static void initHero();

    static std::map<std::string, Hero> heroes;
};
