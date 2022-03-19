#pragma once
#include <string>
#include "functions.h"

class Fraction
{
private:
    std::string name;
    int heroReputation;
    int attitude;

public:
    Fraction();
    Fraction(std::string name, int heroReputation, int attitude);
    virtual ~Fraction();

    void addRep(int rep);
    void removeRep(int rep);
    void setAttitude(int attitude);
    std::string printAttitude();

    inline const std::string& getName() const { return this->name; };
    inline const int& getReputation() const { return this->heroReputation; };
    inline const int& getAttitude() const { return this->attitude; };
};