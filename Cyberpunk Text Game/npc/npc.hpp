#pragma once
#include "../utilities/utilities.hpp"
#include "../fraction/fraction.hpp"

class Npc
{
private:
    std::string name;
    int sex;
    Fraction fraction;
    int attitude;
    int status;
    bool knowingHero;

public:
    Npc();
    Npc(std::string name, int sex, Fraction fraction);
    Npc(std::string name, int sex, Fraction fraction, int attitude, int status, bool knowingHero);
    virtual ~Npc();

    void setName(std::string name);
    void setAttitude(int attitude);
    void printAttitude();
    void setStatus(int status) { this->status = status; };
    bool isDead();
    void setToKnowHero() { this->knowingHero = true; };

    inline const std::string& getName() const { return this->name; };
    inline const int& getSex() const { return this->sex; };
    inline const Fraction& getFraction() const { return this->fraction; };
    inline const int& getAttitude() const { return this->attitude; };
    inline const int& getStatus() const { return this->status; };
    inline const bool& knowsHero() const { return this->knowingHero; };

    static std::map <std::string, Npc> npcs;
    static void initNpcs_EN();
    static void initNpcs_PL();
};