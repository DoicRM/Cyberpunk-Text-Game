#pragma once
#include "events.h"
#include "inventory.h"

using namespace std;

class Hero
{
    string name;
    int hp;
    string status;
    float money;
    Inventory inventory;

public:
    Hero();
    virtual ~Hero();

    inline const string& getName() const { return this->name; };
    inline const int& getHP() const { return this->hp; };
    inline const string& getStatus() const { return this->status; };
    inline const float& getMoney() const { return this->money; };

    void setName(string name);
    void addHP(int hp);
    void removeHP(int hp);
    void changeStatus(int status);
    void addMoney(float money);
    void delMoney(float money);
};
