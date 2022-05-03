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

    if (this->attitude == Angry) attitude = j["Attitudes"].value("Angry", "");
    else if (this->attitude == Hostile) attitude = j["Attitudes"].value("Hostile", "");
    else if (this->attitude == Friendly) attitude = j["Attitudes"].value("Friendly", "");
    else attitude = j["Attitudes"].value("Neutral", "");

    return attitude;
}

void Fraction::initFractions()
{
    Logger::out("Function starts", "Fraction::initFractions");

    Fraction None(j["Fractions"].value("None_Name",""), 0, Neutral);
    Fraction Beggars(j["Fractions"].value("Beggars_Name", ""), 0, Neutral);
    Fraction Police(j["Fractions"].value("Police_Name", ""), 0, Neutral);
    Fraction Hammers(j["Fractions"].value("Hammers_Name", ""), 0, Neutral);
    Fraction Sleepers(j["Fractions"].value("Sleepers_Name", ""), 0, Neutral);
    Fraction SowersOfConfusion(j["Fractions"].value("SowersOfConfusion_Name", ""), 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["SowersOfConfusion"] = SowersOfConfusion;
}