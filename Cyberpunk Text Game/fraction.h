#pragma once
#include <string>
#include "functions.h"

using namespace std;

class Fraction
{
private:
    string name;
    int heroReputation;
    string attitudeToHero;

public:
    Fraction();
    Fraction(string name, int heroReputation, string attitudeToHero);
    virtual ~Fraction();

    void addRep(int rep);
    void delRep(int rep);
    void setAttitude(int attitude);

    inline const string& getName() const { return this->name; };
    inline const int& getReputation() const { return this->heroReputation; };
    inline const string& getAttitude() const { return this->attitudeToHero; };
};