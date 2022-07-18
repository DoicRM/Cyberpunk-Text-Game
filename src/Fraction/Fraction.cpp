#include "Fraction.hpp"

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
        return json["attitude"]["angry"];
    }
    else if (this->attitude == Attitude::Hostile)
    {
        return json["attitude"]["hostile"];
    }
    else if (this->attitude == Attitude::Friendly)
    {
        return json["attitude"]["friendly"];
    }

    return json["attitude"]["neutral"];
}

void Fraction::initFractions()
{
    Logger::startFuncLog(__FUNCTION__);

    Fraction None(json["fractions"]["none"]["name"], 0, Attitude::Neutral);
    Fraction Beggars(json["fractions"]["beggars"]["name"], 0, Attitude::Neutral);
    Fraction Police(json["fractions"]["police"]["name"], 0, Attitude::Neutral);
    Fraction Hammers(json["fractions"]["hammers"]["name"], 0, Attitude::Neutral);
    Fraction Sleepers(json["fractions"]["sleepers"]["name"], 0, Attitude::Neutral);
    Fraction Shitheads(json["fractions"]["shitheads"]["name"], 0, Attitude::Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["Shitheads"] = Shitheads;
}