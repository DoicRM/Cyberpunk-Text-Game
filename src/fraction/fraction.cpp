#include "fraction.hpp"

std::map <std::string, Fraction> Fraction::fractions;

Fraction::Fraction()
{
    this->name = "None";
    this->heroReputation = 0;
    this->attitude = Attitude::Neutral;
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
        return jWriter["attitude"]["angry"];
    }
    else if (this->attitude == Attitude::Hostile)
    {
        return jWriter["attitude"]["hostile"];
    }
    else if (this->attitude == Attitude::Friendly)
    {
        return jWriter["attitude"]["friendly"];
    }

    return jWriter["attitude"]["neutral"];
}

void Fraction::initFractions()
{
    Logger::startFuncLog(__FUNCTION__);

    Fraction None(jWriter["fractions"]["none"]["name"], 0, Attitude::Neutral);
    Fraction Beggars(jWriter["fractions"]["beggars"]["name"], 0, Attitude::Neutral);
    Fraction Police(jWriter["fractions"]["police"]["name"], 0, Attitude::Neutral);
    Fraction Hammers(jWriter["fractions"]["hammers"]["name"], 0, Attitude::Neutral);
    Fraction Sleepers(jWriter["fractions"]["sleepers"]["name"], 0, Attitude::Neutral);
    Fraction Shitheads(jWriter["fractions"]["shitheads"]["name"], 0, Attitude::Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["Shitheads"] = Shitheads;
}