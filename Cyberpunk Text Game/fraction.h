#pragma once
#include <string>
#include "functions.h"
#include "npc.h"

using namespace std;

class Fraction
{
private:
    string name;
    Npc leader;
    int heroReputation;
    string attitudeToHero;

public:
    Fraction();
    Fraction(string name, int heroReputation, string attitudeToHero);
    Fraction(string name, Npc leader, int heroReputation, string attitudeToHero);
    virtual ~Fraction();

    void addRep(int rep);
    void removeRep(int rep);
    void setAttitude(int attitude);
    void setLeader(Npc leader);

    inline const string& getName() const { return this->name; };
    inline const int& getReputation() const { return this->heroReputation; };
    inline const string& getAttitude() const { return this->attitudeToHero; };
};