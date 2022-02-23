#pragma once
#include "functions.h"
#include "fraction.h"

using namespace std;

class Npc
{
private:
    string name;
    Fraction fraction;
    string attitude;
    string status;
    bool knowsHero;

public:
    Npc();
    Npc(string name, Fraction fraction);
    Npc(string name, Fraction fraction, string attitude, string status, bool knowsHero);
    virtual ~Npc();

    void setAttitude(int attitude);
    void kill();
    void setToKnowHero();
    bool isDead();
    bool isKnowsHero();

    inline const string& getName() const { return this->name; };
    inline const Fraction& getFraction() const { return this->fraction; };
    inline const string& getAttitude() const { return this->attitude; };
    inline const string& getStatus() const { return this->status; };
};

enum status
{
    alive = 0,
    dead
};