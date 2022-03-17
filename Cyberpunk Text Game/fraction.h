#pragma once
#include <string>
#include "functions.h"

using namespace std;

class Fraction
{
private:
    string name;
    int heroReputation;
    int attitude;

public:
    Fraction();
    Fraction(string name, int heroReputation, int attitude);
    virtual ~Fraction();

    void addRep(int rep);
    void removeRep(int rep);
    void setAttitude(int attitude);
    string printAttitude();

    inline const string& getName() const { return this->name; };
    inline const int& getReputation() const { return this->heroReputation; };
    inline const int& getAttitude() const { return this->attitude; };
};