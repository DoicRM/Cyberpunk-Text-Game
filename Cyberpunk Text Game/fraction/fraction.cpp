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

    if (this->attitude == Angry) attitude = jWriter["Attitudes"].value("Angry", "");
    else if (this->attitude == Hostile) attitude = jWriter["Attitudes"].value("Hostile", "");
    else if (this->attitude == Friendly) attitude = jWriter["Attitudes"].value("Friendly", "");
    else attitude = jWriter["Attitudes"].value("Neutral", "");

    return attitude;
}

void Fraction::initFractions()
{
    Logger::out("Function starts", "Fraction::initFractions");

    Fraction None(jWriter["Fractions"].value("None_Name",""), 0, Neutral);
    Fraction Beggars(jWriter["Fractions"].value("Beggars_Name", ""), 0, Neutral);
    Fraction Police(jWriter["Fractions"].value("Police_Name", ""), 0, Neutral);
    Fraction Hammers(jWriter["Fractions"].value("Hammers_Name", ""), 0, Neutral);
    Fraction Sleepers(jWriter["Fractions"].value("Sleepers_Name", ""), 0, Neutral);
    Fraction SowersOfConfusion(jWriter["Fractions"].value("SowersOfConfusion_Name", ""), 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["SowersOfConfusion"] = SowersOfConfusion;
}