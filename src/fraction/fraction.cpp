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
    if (this->attitude == Attitude::Angry)
    {
        return jWriter["Attitudes"]["Angry"];
    }
    else if (this->attitude == Attitude::Hostile)
    {
        return jWriter["Attitudes"]["Hostile"];
    }
    else if (this->attitude == Attitude::Friendly)
    {
        return jWriter["Attitudes"]["Friendly"];
    }

    return jWriter["Attitudes"]["Neutral"];
}

void Fraction::initFractions()
{
    Logger::startFuncLog(__FUNCTION__);

    Fraction None(jWriter["Fractions"]["None_Name"], 0, Attitude::Neutral);
    Fraction Beggars(jWriter["Fractions"]["Beggars_Name"], 0, Attitude::Neutral);
    Fraction Police(jWriter["Fractions"]["Police_Name"], 0, Attitude::Neutral);
    Fraction Hammers(jWriter["Fractions"]["Hammers_Name"], 0, Attitude::Neutral);
    Fraction Sleepers(jWriter["Fractions"]["Sleepers_Name"], 0, Attitude::Neutral);
    Fraction SowersOfConfusion(jWriter["Fractions"]["SowersOfConfusion_Name"], 0, Attitude::Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["SowersOfConfusion"] = SowersOfConfusion;
}