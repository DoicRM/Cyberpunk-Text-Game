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
    if (this->attitude == Angry)
    {
        return jWriter.at("Attitudes").value("Angry", JSON_VALUE_ERROR);
    }
    else if (this->attitude == Hostile)
    {
        return jWriter.at("Attitudes").value("Hostile", JSON_VALUE_ERROR);
    }
    else if (this->attitude == Friendly)
    {
        return jWriter.at("Attitudes").value("Friendly", JSON_VALUE_ERROR);
    }

    return jWriter.at("Attitudes").value("Neutral", JSON_VALUE_ERROR);
}

void Fraction::initFractions()
{
    Logger::startFuncLog(__FUNCTION__);

    Fraction None(jWriter.at("Fractions").value("None_Name", JSON_VALUE_ERROR), 0, Neutral);
    Fraction Beggars(jWriter.at("Fractions").value("Beggars_Name", JSON_VALUE_ERROR), 0, Neutral);
    Fraction Police(jWriter.at("Fractions").value("Police_Name", JSON_VALUE_ERROR), 0, Neutral);
    Fraction Hammers(jWriter.at("Fractions").value("Hammers_Name", JSON_VALUE_ERROR), 0, Neutral);
    Fraction Sleepers(jWriter.at("Fractions").value("Sleepers_Name", JSON_VALUE_ERROR), 0, Neutral);
    Fraction SowersOfConfusion(jWriter.at("Fractions").value("SowersOfConfusion_Name", JSON_VALUE_ERROR), 0, Neutral);

    fractions["None"] = None;
    fractions["Beggars"] = Beggars;
    fractions["Police"] = Police;
    fractions["Hammers"] = Hammers;
    fractions["Sleepers"] = Sleepers;
    fractions["SowersOfConfusion"] = SowersOfConfusion;
}