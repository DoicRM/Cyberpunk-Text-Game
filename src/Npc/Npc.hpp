#pragma once
#include "../Fraction/Fraction.hpp"
#include "../Utilities/Utilities.hpp"

enum Sex
{
    Undefined, Male, Female
};

enum CharacterStatus
{
    Normal, Unconscious, Dead
};

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

    void setName(std::string name) { this->name = name; }
    void setSex(int sex) { this->sex = sex; }
    void setFraction(Fraction fraction);
    void setAttitude(int attitude);
    void printAttitude();
    void setStatus(int status) { this->status = status; }
    bool isDead();
    void setToKnowHero() { this->knowingHero = true; }

    inline const std::string& getName() const { return this->name; }
    inline const int& getSex() const { return this->sex; }
    inline const Fraction& getFraction() const { return this->fraction; }
    inline const int& getAttitude() const { return this->attitude; }
    inline const int& getStatus() const { return this->status; }
    inline const bool& knowsHero() const { return this->knowingHero; }

    static void initNpcs();

    friend class cHero;

    static std::map <std::string, Npc> npcs;
};