#pragma once
#include "functions.h"
#include "fraction.h"

class Npc
{
private:
    std::string name;
    Fraction fraction;
    int attitude;
    int status;
    bool knowingHero;

public:
    Npc();
    Npc(std::string name, Fraction fraction);
    Npc(std::string name, Fraction fraction, int attitude, int status, bool knowingHero);
    virtual ~Npc();

    void setAttitude(int attitude);
    void printAttitude();
    void setStatus(int status);
    bool isDead();
    void setToKnowHero();
    bool knowsHero();

    inline const std::string& getName() const { return this->name; };
    inline const Fraction& getFraction() const { return this->fraction; };
    inline const int& getAttitude() const { return this->attitude; };
    inline const int& getStatus() const { return this->status; };
};