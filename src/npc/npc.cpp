#include "npc.hpp"

std::map <std::string, Npc> Npc::npcs;

Npc::Npc()
{
    this->name = "None";
    this->sex = Undefined;
    this->fraction = Fraction();
    this->attitude = Neutral;
    this->status = Normal;
    this->knowingHero = false;
}

Npc::Npc(std::string name, int sex, Fraction fraction)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = Neutral;
    this->status = Normal;
    this->knowingHero = false;
}


Npc::Npc(std::string name, int sex, Fraction fraction, int attitude, int status, bool knowingHero)
{
    this->name = name;
    this->sex = sex;
    this->fraction = fraction;
    this->attitude = attitude;
    this->status = status;
    this->knowingHero = knowingHero;
}

Npc::~Npc()
{
}

void Npc::setName(std::string name)
{
    this->name = name;
}

void Npc::setSex(int sex)
{
    this->sex = sex;
}

void Npc::setFraction(Fraction fraction)
{
    this->fraction = fraction;
}

void Npc::setAttitude(int attitude)
{
    this->attitude = attitude;
    printAttitude();
}

void Npc::printAttitude()
{
    std::string attitude;

    if (this->attitude == Attitude::Angry)
    {
        attitude = jWriter["Attitudes"]["Angry"];
        Console::setConsoleColor(ConsoleColor::CC_Yellow);
    }
    else if (this->attitude == Attitude::Hostile)
    {
        attitude = jWriter["Attitudes"]["Hostile"];
        Console::setConsoleColor(ConsoleColor::CC_Red);
    }
    else if (this->attitude == Attitude::Friendly)
    {
        attitude = jWriter["Attitudes"]["Friendly"];
        Console::setConsoleColor(ConsoleColor::CC_Green);
    }
    else
    {
        attitude = jWriter["Attitudes"]["Neutral"];
        Console::resetConsoleColor();
    }

    Display::write("\t" + this->name + (std::string)jWriter["Attitudes"]["Is"] + attitude + (std::string)jWriter["Attitudes"]["Now"]);
    Console::resetConsoleColor();
}

bool Npc::isDead()
{
    if (status != Dead)
    {
        return false;
    }

    return true;
}

void Npc::initNpcs()
{
    Logger::startFuncLog(__FUNCTION__);
    // PROLOG
    Npc Bob("Bob", Male, Fraction::fractions["Beggars"]);
    Npc Caden("Caden", Male, Fraction::fractions["Police"]);
    Npc CadensPartner(jWriter["Npcs"]["Policeman_Name"], Male, Fraction::fractions["Police"]);
    Npc Zed("Zed", Male, Fraction::fractions["None"]);
    Npc Nyx("Nyx", Female, Fraction::fractions["Sleepers"]);
    Npc Jet(jWriter["Npcs"]["Bouncer_Name"], Male, Fraction::fractions["Hammers"]);
    Npc Vincent("Vincent", Male, Fraction::fractions["Hammers"]);
    Npc Enigma("Enigma", Male, Fraction::fractions["None"]);
    // AKT I
    Npc Morpheus(jWriter["Npcs"]["Morpheus_Name"], Male, Fraction::fractions["Sleepers"]);
    Npc MerQRy("Mer Q'Ry", Male, Fraction::fractions["None"]);
    Npc Karla("Karla", Female, Fraction::fractions["None"]);
    Npc ChipCaine("Chip Caine", Male, Fraction::fractions["None"]);
    Npc JaxRasac("Jax Rasac", Male, Fraction::fractions["SowersOfConfusion"]);

    npcs["Bob"] = Bob;
    npcs["Caden"] = Caden;
    npcs["CadensPartner"] = CadensPartner;
    npcs["Zed"] = Zed;
    npcs["Nyx"] = Nyx;
    npcs["Jet"] = Jet;
    npcs["Vincent"] = Vincent;
    npcs["Enigma"] = Enigma;
    npcs["Morpheus"] = Morpheus;
    npcs["MerQRy"] = MerQRy;
    npcs["Karla"] = Karla;
    npcs["ChipCaine"] = ChipCaine;
    npcs["JaxRasac"] = JaxRasac;
}