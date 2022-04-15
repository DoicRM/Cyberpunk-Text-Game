#include "fraction.hpp"

std::map <std::string, Fraction> Fraction::fractions;

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitude = Neutral;
}

Fraction::Fraction(std::string name, int heroReputation, int attitude)
{
    this->name = name;
    this->heroReputation = heroReputation;
    this->attitude = attitude;
}

Fraction::~Fraction()
{
}

std::string Fraction::printAttitude()
{
    std::string attitude;

    if (this->attitude == Angry) attitude = "angry";
    else if (this->attitude == Hostile) attitude = "hostile";
    else if (this->attitude == Friendly) attitude = "friendly";
    else attitude = "neutral";

    return attitude;
}

void Fraction::initFractions_EN()
{
    Logger::out("Function starts", "Fraction::initFractions_EN");

    Fraction None("None", 0, Neutral);
    Fraction Beggars("Beggars", 0, Neutral);
    Fraction Police("Police", 0, Neutral);
    Fraction Hammers("Hammers", 0, Neutral);
    Fraction Sleepers("Sleepers", 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
}

void Fraction::initFractions_PL()
{
    Logger::out("Function starts", "Fraction::initFractions_PL");

    Fraction None("Brak", 0, Neutral);
    Fraction Beggars("¯ebracy", 0, Neutral);
    Fraction Police("Policja", 0, Neutral);
    Fraction Hammers("M³oty", 0, Neutral);
    Fraction Sleepers("Œni¹cy", 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
}