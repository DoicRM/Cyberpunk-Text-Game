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

    if (this->attitude == Angry) attitude = JSON::getValue("Attitude_Angry");
    else if (this->attitude == Hostile) attitude = JSON::getValue("Attitude_Hostile");
    else if (this->attitude == Friendly) attitude = JSON::getValue("Attitude_Friendly");
    else attitude = JSON::getValue("Attitude_Neutral");

    return attitude;
}

void Fraction::initFractions()
{
    Logger::out("Function starts", "Fraction::initFractions");

    Fraction None(JSON::getValue("Fraction_None_Name"), 0, Neutral);
    Fraction Beggars(JSON::getValue("Fraction_Beggars_Name"), 0, Neutral);
    Fraction Police(JSON::getValue("Fraction_Police_Name"), 0, Neutral);
    Fraction Hammers(JSON::getValue("Fraction_Hammers_Name"), 0, Neutral);
    Fraction Sleepers(JSON::getValue("Fraction_Sleepers_Name"), 0, Neutral);
    Fraction SowersOfConfusion(JSON::getValue("Fraction_SowersOfConfusion_Name"), 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["SowersOfConfusion"] = SowersOfConfusion;
}