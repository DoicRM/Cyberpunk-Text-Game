#pragma once
#include <string>

using namespace std;

class Fraction
{
    string name;
    int heroReputation;
    string attitudeToHero;

public:
    Fraction();
    Fraction(string name, int heroReputation, string attitudeToHero);
    virtual ~Fraction();

    inline const string& getName() const { return this->name; };
    inline const int& getReputation() const { return this->heroReputation; };
    inline const string& getAttitude() const { return this->attitudeToHero; };

    void setOwner(Fraction owner);
};