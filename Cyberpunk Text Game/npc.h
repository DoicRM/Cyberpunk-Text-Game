#pragma once
#include "functions.h"
#include "fraction.h"

using namespace std;

class Npc
{
private:
    string name;
    Fraction fraction;
    int attitude;
    int status;
    bool knowingHero;

public:
    Npc();
    Npc(string name, Fraction fraction);
    Npc(string name, Fraction fraction, int attitude, int status, bool knowingHero);
    virtual ~Npc();

    void setAttitude(int attitude);
    void printAttitude();
    void setStatus(int status);
    bool isDead();
    void setToKnowHero();
    bool knowsHero();

    inline const string& getName() const { return this->name; };
    inline const Fraction& getFraction() const { return this->fraction; };
    inline const int& getAttitude() const { return this->attitude; };
    inline const int& getStatus() const { return this->status; };
};